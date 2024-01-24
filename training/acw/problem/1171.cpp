#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = N * 2;

int h[N], ne[M], e[M], idx, w[M];
int n, m;
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int dist[N], lc[N][20], dep[N], st[N];

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	st[u] = true;
	for(int k = 1; k <= 15; k ++) lc[u][k] = lc[lc[u][k - 1]][k - 1];
	for(int i = h[u];i != -1; i = ne[i]) {
		int j = e[i];
		if(st[j]) continue;
		dist[j] = dist[u] + w[i];
		dfs(j, u);
	}
}

int LCA(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int k = 15; k >= 0; k --)
		if(dep[lc[a][k]] >= dep[b])
			a = lc[a][k];
	if(a == b) return a;
	for(int k = 15; k >= 0; k --)
		if(lc[a][k] != lc[b][k])
			a = lc[a][k], b = lc[b][k];
	return lc[a][0];
}

void solve() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1;i < n; i ++) {
		int a, b, c; cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dfs(1, 0);
	while(m --) {
		int a, b; cin >> a >> b;
		int t = LCA(a, b);
		cout << dist[b] + dist[a] - 2 * dist[lc[t][0]] << '\n';
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}