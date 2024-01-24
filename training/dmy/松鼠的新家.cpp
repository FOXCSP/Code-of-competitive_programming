#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 300010;

int n, m;
int dep[N], fa[N][20], a[N];
ll tag[N];
vector<int> e[N];

void dfs1(int u, int f) {
	dep[u] = dep[f] + 1;
	fa[u][0] = f;
	for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : e[u]) {
		if (v == f) continue;
		dfs1(v, u);
	}
}

void dfs2(int u, int f) {
	for (auto v : e[u]) {
		if (v != f) {
			dfs2(v, u);
			tag[u] += tag[v];
		}
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--) {
		if (dep[fa[u][i]] >= dep[v]) {
			u = fa[u][i];
		}
	}
	if (u == v) return u;
	for (int i = 19; i >= 0; i--) {
		if (fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1, 0);
	for (int i = 1; i < n; i++) {
		int f = lca(a[i], a[i + 1]);
		tag[a[i]]++, tag[a[i+1]]++, tag[fa[f][0]]--, tag[f]--;
	}
	dfs2(1, 0);
	for (int i = 2; i <= n; i++) tag[a[i]]--;
	for (int i = 1; i <= n; i++) printf("%d\n", tag[i]);
}

int main() {
	solve();
	return 0;
}