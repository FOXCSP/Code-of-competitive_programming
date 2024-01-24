#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define PII pair<int,int>
#define PLL pair<ll, ll>
#define VI vector<int>
#define SZ(x) ((int)x.size())
#define VL vector<ll>;
#define VPP vector<PII>
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--

const int N = 110;
vector<int> e[N];
int n, m, idx;
map<ll, int> mp, id;
ll idg[N], odg[N], a[N], res[N], tot, st[N], pos[N];

void tpsort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		int u = id[a[i]];
		if (idg[u] == 0 && odg[u] == 1) {
			q.push(u);
		}
	}
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		res[++tot] = u;
		if (st[u]) continue;
		st[u] = 1;
		for (auto v : e[u]) {
			if (!st[v] && !(--idg[v])) {
				q.push(v);
			}
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		id[a[i]] = ++idx;
		pos[idx] = a[i];
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] % 3 == 0 && mp[a[i] / 3]) {
			e[id[a[i]]].pb(id[a[i] / 3]);
			odg[id[a[i]]]++;
			idg[id[a[i] / 3]]++;
		}
		if (mp[a[i] * 2]) {
			e[id[a[i]]].pb(id[a[i] * 2]);
			odg[id[a[i]]]++;
			idg[id[a[i] * 2]]++;
		}
	}
	tpsort();
	for (int i = 1; i <= tot; i++) {
		cout << pos[res[i]] << " \n"[i == n];
	}
}

int main() {
	solve();
	return 0;
}

// 3 6 2
// 6 12 4