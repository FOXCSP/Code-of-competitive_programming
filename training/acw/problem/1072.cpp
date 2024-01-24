// Problem: 树的最长路径
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/1074/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = N * 2;
int h[N], w[M], e[M], ne[M], idx;
int dist[N], n;
bool st[N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int d[N], ans = 0;

void dfs(int u) {
	st[u] = 1;
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(st[j]) continue;
		dfs(j);
		ans = max(ans, d[u] + d[j] + w[i]);
		d[u] = max(d[u], d[j] + w[i]);
	}
}

void solve() {
	cin >> n;
	memset(h, -1, sizeof h);
	for(int i = 1;i < n;i ++) {
		int a, b, c; cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dfs(1);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}