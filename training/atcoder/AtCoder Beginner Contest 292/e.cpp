#include <bits/stdc++.h>
#define fi first
#define se second
#define lp (p<<1)
#define rp (p<<1|1)
#define pb emplace_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setop(T) cout<<fixed<<setprecision(T);
using namespace std;
using ll = long long;

const int N = 2010;
vector<int> e[N];
int n, m;
int vis[N], ans;

void dfs(int u) {
	vis[u] = 1;
	for (int v : e[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
}

void solve(int caseT) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		dfs(i);
		ans += count(vis + 1, vis + n + 1, 1);
		ans -= (1 + SZ(e[i]));
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _;
	_=1;	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}