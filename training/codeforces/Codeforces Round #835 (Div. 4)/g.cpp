#include <bits/stdc++.h>
#define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define PII pair<int,int>
#define VI vector<int>
#define SZ(x) ((int)x.size())
using namespace std;
using ll=unsigned long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--

const int N = 100010;

int n, a, b;
bool flg, over;
vector<pair<ll, ll>> e[N];
set<int> S;

void dfs1(int u, int fa, int x) {
	for (auto [v, w] : e[u]) {
		if (v == fa) continue;
		S.insert(x ^ w);
		dfs1(v, u, x ^ w);
	}
}

bool dfs2(int u, int fa, int x) {
	if (u != b && S.count(x)) {
		return true;
	}
	for (auto [v, w] : e[u]) {
		if (v == fa || v == b) continue;
		if (dfs2(v, u, x ^ w)) return true;
	}
	return false;
}


void solve() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) e[i].clear();
	S.clear();
	for (int i = 1; i < n; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		e[u].pb({v, w});
		e[v].pb({u, w});
	}
	dfs1(b, 0, 0);
	puts(dfs2(a, 0, 0) ? "YES" : "NO");
}


signed main() {
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}