#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, m;
vector<int> e[N];
int sz[N], hs[N], fa[N], tot, dep[N];
int top[N], l[N], r[N], id[N];
// 第一遍dfs求出子树大小   
void dfs1(int u, int f) {
	sz[u] = 1;
	hs[u] = -1;
	fa[u] = f;
	dep[u] = dep[f] + 1;
	for (auto v : e[u]) {
		if (v == f) continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if (hs[u] == -1 || sz[v] > sz[hs[u]])
			hs[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	l[u] = ++tot;
	id[tot] = u;
	if (hs[u] != -1) {
		dfs2(hs[u], t);
	}
	for (auto v : e[u]) {
		if (v != fa[u] && v != hs[u]) {
			dfs2(v, v);
		}
	}
	r[u] = tot;
}

int LCA(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) v = fa[top[v]];
		else u = fa[top[u]];
	}
	if (dep[u] < dep[v]) return u;
	else return v;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", LCA(u, v));
	}
}

int main() {
	solve();
	return 0;
}