#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = 18;

int par[N][M + 1], depth[N], val[N][M + 1], n, q;
vector<pair<int, int>> e[N];

void dfs(int u, int fa) {
	depth[u] = depth[fa] + 1;
	for (auto p : e[u]) {
		int v = p.first;
		if (v == fa) continue;
		par[v][0] = u;
		val[v][0] = p.second;
		dfs(v, u);
	}
}

int query(int u, int v) {
	int ans = 1 << 30;
	if (depth[u] < depth[v]) skwap(u, v);
	for (int k = M; k >= 0; k--) {
		if (depth[par[u][k]] >= depth[v]) {
			ans = min(ans, val[u][k]);
			u = par[u][k];
		}
	}
	if (u == v) return ans;
	for (int k = M; k >= 0; k--) {
		if (par[u][k] != par[v][k]) {
			ans = min(ans, min(val[u][k], val[v][k]));
			u = par[u][k];
			v = par[v][k];
		}
	}
	return min(ans, min(val[u][0], val[v][0]));
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
	}
	dfs(1, 0);
	for (int j = 1; j <= M; j++) {
		for (int u = 1; u <= n; u++) {
			par[u][j] = par[par[u][j - 1]][j - 1];
			val[u][j] = min(val[u][j - 1], val[par[u][j - 1]][j - 1]);
		}
	}
	for (int i = 1; i <= q; i++) {
		int u, v; cin >> u >> v;
		cout << query(u, v) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}