#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)

using namespace std;
const int N = 100010;
int n, m;
int a[N], id[N], tot, top[N], fa[N], dep[N], l[N], r[N], sz[N], hs[N];
vector<int> e[N];

struct info {
	int num, ln, rn;
};

info operator + (const info& l, const info& r) {
	return (info) {l.num + r.num - (l.rn == r.ln), l.ln, r.rn};
}

struct seg {
	info val;
	int tag;
} tr[N << 4];

void pushup(int p) {
	tr[p].val = tr[lp].val + tr[rp].val;
}

void build(int p, int l, int r) {
	if (l == r) {
		tr[p].val = {1, a[id[l]], a[id[l]]};
	} else {
		int mid = (l + r) / 2;
		build(lp, l, mid), build(rp, mid + 1, r);
		pushup(p);
	}
}

void settag(int p, int tag) {
	tr[p].val = {1, tag, tag};
	tr[p].tag = tag;
}

void pushdown(int p) {
	if (tr[p].tag) {
		settag(lp, tr[p].tag);
		settag(rp, tr[p].tag);
		tr[p].tag = 0;
	}
}

void modify(int p, int l, int r, int L, int R, int d) {
	if (L <= l && r <= R) {
		settag(p, d);
	} else {
		pushdown(p);
		int mid = (l + r) / 2;
		if (L <= mid) modify(lp, l, mid, L, R, d);
		if (R > mid) modify(rp, mid + 1, r, L, R, d);
		pushup(p);
	}
}

info query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tr[p].val;
	pushdown(p);
	int mid = (l + r) / 2;
	if (L > mid) return query(rp, mid + 1, r, L, R);
	else if (R <= mid) return query(lp, l, mid, L, R);
	else return query(lp, l, mid, L, R) + query(rp, mid + 1, r, L, R);
}

int query(int u, int v) {
	info ansv = {0, 0, 0}, ansu = {0, 0, 0};
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			ansv = query(1, 1, n, l[top[v]], l[v]) + ansv;
			v = fa[top[v]];
		} else {
			ansu = query(1, 1, n, l[top[u]], l[u]) + ansu;
			u = fa[top[u]];
		}
	}
	if (dep[u] <= dep[v]) ansv = query(1, 1, n, l[u], l[v]) + ansv;
	else ansu = query(1, 1, n, l[v], l[u]) + ansu;
	return (ansu.num + ansv.num - (ansu.ln == ansv.ln));
}

void modify(int u, int v, int d) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			modify(1, 1, n, l[top[v]], l[v], d);
			v = fa[top[v]];
		} else {
			modify(1, 1, n, l[top[u]], l[u], d);
			u = fa[top[u]];
		}
	}
	if (dep[u] <= dep[v]) modify(1, 1, n, l[u], l[v], d);
	else modify(1, 1, n, l[v], l[u], d);
}

void dfs1(int u, int f) {
	sz[u] = 1;
	hs[u] = -1;
	dep[u] = dep[f] + 1;
	fa[u] = f;
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

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		char op[10];
		int a, b, c;
		scanf("%s", op);
		if (op[0] == 'C') {
			scanf("%d%d%d", &a, &b, &c);
			modify(a, b, c);
		} else {
			scanf("%d%d", &a, &b);
			int ans = query(a, b);
			printf("%d\n", ans);
		}
	}
}

int main() {
	solve();
	return 0;
}