#include <bits/stdc++.h>

using namespace std;

const int N = 25010, M = N * 2;
int h[N], e[M], ne[M], dist[N], w[M], idx, id[N], bcnt;
vector<int> sid[N];
bool st[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int ans = 0, s, n, m;

void dijkstra() {}

void dfs(int u, int cnt) {
	id[u] = cnt;
	sid[cnt].push_back(u);
	for(int i = h[u]; i != -1; i = ne[i]) {
		if(!id[e[i]]) dfs(e[i], cnt);
	}
}

void solve() {
	int r, c;
	cin >> n >> r >> c >> s;
	memset(h, -1, sizeof h);
	while(r --) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	for(int i = 1; i <= n; i ++)
		if(!id[i]) dfs(i, ++ bcnt);
	while(c --) {
		
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}