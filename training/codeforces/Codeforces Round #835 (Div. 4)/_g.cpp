#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define PII pair<int,int>
#define VI vector<int>
#define SZ(x) ((int)x.size())
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--

const int N = 200010;

int n, a, b;
bool flg, over;
vector<pair<ll, ll>> e[N];
map<ll, ll> st, cnt, check;

void bfs(int u) {
	queue<pair<ll, ll>> q;
	q.push({0, u});
	while (!q.empty()) {
		auto [d, x] = q.front();
		q.pop();
		if (st[x]) continue;
		st[x] = 1;
		for (auto [v, w] : e[x]) {
			if (st[v] == 0) {
				cnt[w ^ d]++;
				q.push({w ^ d, v});
			}
		}
	}
}

void bfs2(int u) { 
	queue<pair<ll, ll>> q;
	q.push({0, u});
	while (!q.empty()) {
		auto [d, x] = q.front();
		q.pop();
		if (st[x]) continue;
		st[x] = 1;
		for (auto [v, w] : e[x]) {
			if (st[v] == 0 && v != b) {
				check[w ^ d]++;
				q.push({w ^ d, v});
			}
		}
	}
}


void solve() {
	cin >> n >> a >> b;
	flg = over = 0;
	cnt.clear();
	check.clear();
	for (int i = 1; i < n; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		e[u].pb({v, w});
		e[v].pb({u, w});
	}
	st.clear();
	bfs(b);
	st.clear();
	bfs2(a);
	for (auto c : cnt) {
		if (check[c.first]) {
			flg = 1;
			break;
		}
	}
	puts(flg ? "YES" : "NO");
	for (int i = 1; i <= n; i++) e[i].clear();
}


signed main() {
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}