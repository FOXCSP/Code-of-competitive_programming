#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int sz[N], n;
vector<int> e[N];

void dfs(int u, int fa) {
	sz[u] = 1;
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
void reset(int u, int fa) {
	sz[u] = 0;
	for (auto v : e[u]) {
		if (v == fa) continue;
		reset(v, u);
	}
}

multiset<int> f, s;
int ans = 1 << 30;

void update(int a, int b) {
	int x = max({a, b, n - a - b});
	int y = min({a, b, n - a - b});
	ans = min(ans, x - y);
}

void dfs2(int u, int fa) {
	// u为第一刀
	// 1 是u的father
	if (!f.empty()) {
		auto it = f.lower_bound((n - sz[u]) / 2 + sz[u]);
		if (it != f.end()) {
			update(sz[u], *it - sz[u]);
		}
		if (it != f.begin()) {
			it--;
			update(sz[u], *it - sz[u]);
		}
	}
	// 2 在之前的子树上
	// printf("%d\n", s.size());
	if (!s.empty()) {
		auto it = s.lower_bound((n - sz[u]) / 2);
		if (it != s.end()) {
			update(sz[u], *it);
		}
		if (it != s.begin()) {
			it--;
			update(sz[u], *it);
		}
	}
	f.insert(sz[u]);
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs2(v, u);
	}
	s.insert(sz[u]);
	f.erase(f.find(sz[u]));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	dfs2(1, 0);
	printf("%d\n", ans);
	return 0;
}