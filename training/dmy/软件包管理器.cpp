#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], n, m;
vector<int> e[N];
#define lp (p<<1)
#define rp (p<<1|1)

int dep[N], fa[N], id[N], tot;
int l[N], r[N], sz[N], dfn[N], hs[N];

struct seg {
	int sum;
	int sz;
	int t;
} tr[N << 4];

void pushup(int p) {
	tr[p].sum = tr[lp].sum + tr[rp].sum;
}

void build(int p, int l, int r) {
	tr[p].sz = r - l + 1;
	tr[p].t = -1;
	if (l == r) {
		tr[p].sum = 0;
	} else {
		int mid = (l + r) / 2;
		build(lp, l, mid), build(rp, mid + 1, r);
		pushup(p);
	}
}

void settag(int p, int t) {
	if (t == 1) {
		tr[p].sum = tr[p].sz;
	} else {
		tr[p].sum = 0;
	}
	tr[p].t = t;
}

void pushdown(int p) {
	if (tr[p].t != -1) {
		settag(lp, tr[p].t);
		settag(rp, tr[p].t);
		tr[p].t = -1;
	}
}

void modify(int p, int l, int r, int L, int R, int t) {
	if (L <= l && r <= R) {
		settag(p, t);
	} else {
		pushdown(p);
		int mid = (l + r) / 2;
		if (L <= mid) modify(lp, l, mid, L, R, t);
		if (R > mid) modify(rp, mid + 1, r, L, R, t);
		pushup(p);
	}
}

void install(int x) {
	while (x != 0) {
		modify(1, 1, n, l[dfn[x]], l[x], 1);
		x = fa[dfn[x]];
	}
}

void uninstall(int x) {
	modify(1, 1, n, l[x], r[x], 0);
}

void dfs1(int u, int f) {
	sz[u] = 1;
	dep[u] = dep[f] + 1;
	hs[u] = -1;
	fa[u] = f;
	for (auto v : e[u]) {
		if (v == f) continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if (hs[u] == -1 || sz[v] > sz[hs[u]])
			hs[u] = v;
	}
	r[u] = tot;
}

void dfs2(int u, int t) {
	dfn[u] = t;
	l[u] = ++tot;
	if (hs[u] != -1) dfs2(hs[u], t);
	for (auto v : e[u]) {
		if (v != fa[u] && v != hs[u]) dfs2(v, v);
	}
	r[u] = tot;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		e[i + 1].push_back(x + 1);
		e[x + 1].push_back(i + 1);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	scanf("%d", &m);
	int pre = 0;
	for (int i = 1; i <= m; i++) {
		static char op[10];
		static int x;
		scanf("%s%d", op, &x);
		x += 1;
		if (op[0] == 'i') {
			install(x);
		} else {
			uninstall(x);
		}
		printf("%d\n", abs(pre - tr[1].sum));
		pre = tr[1].sum;
	}
}

int main() {
	solve();
	return 0;
}