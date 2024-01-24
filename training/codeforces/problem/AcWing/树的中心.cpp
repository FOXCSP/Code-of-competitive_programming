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

const int N = 100010;
vector<pair<int, int>> e[N];
int n, m;
int dp[N], hv[N];
int down1[N], down2[N];
int up[N], fa[N], df[N];
vector<int> leafs;
// dfs1 搜出向下的最大深度和次大深度
int dfs1(int u, int f) {
	fa[u] = f;
	for (auto [v, w] : e[u]) {
		if (v == f) continue;
		int t = dfs1(v, u);
		if (down1[u] < t) {
			down2[u] = down1[u];
			down1[u] = t;
		} else if (down2[u] < t) down2[u] = t;
	}
	if (down1[u] == 0) leafs.pb(u);
	return down1[u];
}

int dfs2(int u) {
	if (fa[u] == 0) {
		return up[u] = df[u] + hv[fa[u]] == u ? down2[fa[u]] : down1[fa[u]];
	} else {
		return up[u] = df[u] + max(dfs2(fa[u]), hv[fa[u]] == u ? down2[fa[u]] : down1[fa[u]]);
	}
}


void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].pb({v, w});
		e[v].pb({u, w});
	}
	dfs1(1, 0);
	for (auto x : leafs) {
		dfs2(x);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
	    cout << down1[i] << " " << down2[i] << " " << up[i] << '\n';
	}
	for (int i = 1; i <= n; i++) {
		ans = max(down1[i], up[i]);
	}
	cout << ans << '\n';
}

int main() {
	solve();
	return 0;
}