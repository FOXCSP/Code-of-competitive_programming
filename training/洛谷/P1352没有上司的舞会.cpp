#include <bits/stdc++.h>

using namespace std;
const int N = 6010;
bool st[N];
int fa[N], dp[N][2], w[N], n;
vector<int> e[N];
void dfs(int u) {
	dp[u][1] = w[u];
	dp[u][0] = 0;
	for (auto v : e[u]) {
		dfs(v);
		dp[u][1] += dp[v][0];
		dp[u][0] += max(dp[v][0], dp[v][1]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	int root = 0;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		st[u] = true;
		e[v].push_back(u);
		fa[u] = v;
	}
	for (int i = 1; i <= n; i++) if (!st[i]) {
		root = i; break;
	}
	// printf("xx %d\n", root);
	dfs(root);
	printf("%d\n", max(dp[root][0], dp[root][1]));
	return 0;
}