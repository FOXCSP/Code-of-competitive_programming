#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, m;
int sz[N]; // 子树size
int hs[N]; // 重儿子节点(-1无) 
int id[N]; // tot所属的节点
int l[N], r[N], tot; // dfs序的区间
vector<int> e[N];

void dfs(int u, int fa) {
	l[u] = ++tot;
	id[tot] = u;
	sz[u] = 1;
	hs[u] = -1;
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs(v, u);
		sz[u] += sz[v];
		if (hs[u] == -1 || sz[v] > sz[hs[u]])
			hs[u] = v; 
	}
	r[u] = tot;
}

void DSU(int u, int fa, bool keep) {
	for (auto v : e[u]) // 先算出轻儿子, 信息无需保留
		if (v != fa && v != hs[u]) { 
			DSU(v, u, false);
		}

	if (hs[u] != -1) {
		DSU(hs[u], u, true);
		// 重儿子集合
	}

	for (auto v : e[u]) {
		if (v != fa && v != hs[u]) { // v 是轻儿子
			for (int x = l[v]; x <= r[v]; x++)
				add(id[x]);
		}
	}
	// u本身加入
	add(u);
	if (!keep) {
		// 轻儿子清空
		for (int x = l[u]; x <= r[u]; x++) {
			del(id[x]);
		}
	}
}

int main() {
	// 第一遍dfs求出子树结构
	dfs(1, 0);
	DSU(1, 0, 0);
	return 0;
}