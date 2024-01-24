#include <bits/stdc++.h>

using namespace std;

const int N = 20010;
int n, m;
int h[N], w[N], ne[N], e[N], idx;
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int fa[N][20], depth[N], dist[N];
bool st[N];
void dfs(int u, int father, int v) {
	fa[u][0] = father, depth[u] = depth[father] + 1;
	st[u] = true, dist[u] = dist[father] + v;
	for(int k = 1; k <= 19; k ++) 
		fa[u][k] = fa[fa[u][k - 1]][k - 1];
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(st[j]) continue;
		dfs(j, u, w[i]);
	}
}

int LCA(int a,int b) {
	if(depth[a] < depth[b]) swap(a, b);
	for(int k = 19; k >= 0; k --)
		if(depth[fa[a][k]] >= depth[b])
			a = fa[a][k];
	if(a == b) return a;
	for(int k = 19; k >= 0; k --)
		if(fa[a][k] != fa[b][k])
			a = fa[a][k], b = fa[b][k];
	return fa[a][0];
}
void solve() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1; i < n; i ++) {
		int a, b, c; cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dfs(1, 0, 0);
	while(m --) {
		int l, r; cin >> l >> r;
		int t = LCA(l, r);
		cout << dist[l] + dist[r] - 2 * dist[t] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}