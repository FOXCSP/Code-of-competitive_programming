#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100010;

int hs[N], sz[N], l[N], r[N], tot, id[N];
vector<int> e[N];
int cnt[N];
int a[N], n;
ll sumcnt, maxcnt, ans[N];
void dfs(int u, int fa) {
	sz[u] = 1;
	hs[u] = -1;
	l[u] = ++tot;
	id[tot] = u;
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
	for (auto v : e[u]) {
		if (v != fa && v != hs[u])
			DSU(v, u, false);
	}
	if (hs[u] != -1) {
		DSU(hs[u], u, true);
	}

	auto add = [&](int x) {
		int col = a[x];
		cnt[col]++;
		if (cnt[col] > maxcnt)
			maxcnt = cnt[col], sumcnt = col;
		else if (cnt[col] == maxcnt)
			sumcnt += col;
	};

	auto del = [&](int x) {
		int col = a[x];
		cnt[col]--;
	};

	for (auto v : e[u]) {
		if (v != fa && v != hs[u]) {
			for (int x = l[v]; x <= r[v]; x++)
				add(id[x]);
		}
	}
	add(u);
	ans[u] = sumcnt;
	if (!keep) {
		maxcnt = 0;
		sumcnt = 0;
		for (int x = l[u]; x <= r[u]; x++) {
			del(id[x]);
		}
	}
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	DSU(1, 0, false);
	for (int i = 1; i <= n; i++) 
		printf("%lld%c", ans[i], " \n"[i == n]);
	return 0;
}