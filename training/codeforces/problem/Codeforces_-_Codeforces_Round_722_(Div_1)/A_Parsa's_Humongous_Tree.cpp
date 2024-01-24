#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--
const int N = 100100;
int n;
vector<int> e[N];
ll a[N], b[N];
ll ans = 0;
ll dp[N][2];

void dfs(int u, int fa) {
	for (int v : e[u]) {
		if (v == fa) continue;
		dfs(v, u);
		// ll x = dp[v][0] + abs(min(a[u], b[u]) - min(a[v], b[v]));
		// ll y = dp[v][1] + abs(min(a[u], b[u]) - max(a[v], b[v]));
		dp[u][0] += max(dp[v][0] + abs(a[u] - a[v]), dp[v][1] + abs(a[u] - b[v]));
		// x = dp[v][0] + abs(max(a[u], b[u]) - min(a[v], b[v]));
		// y = dp[v][1] + abs(max(a[u], b[u]) - max(a[v], b[v]));
		dp[u][1] += max(dp[v][0] + abs(b[u] - a[v]), dp[v][1] + abs(b[u] - b[v]));
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) e[i].clear(), dp[i][0] = dp[i][1] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}