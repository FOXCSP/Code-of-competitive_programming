#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)

using namespace std;

const int N = 100010;

int l[N], r[N], id[N], tot;
int sz[N], hs[N], dep[N], fa[N], top[N];
int n, m, a[N];
vector<int> e[N];

struct info {
	int maxv, sum;
};

info operator + (const info &l, const info &r) {
	return (info) {max(l.maxv, r.maxv), l.sum + r.sum};
}

struct seg {
	info val;
} tr[N << 4];

void pushup(int p) {
	tr[p].val = tr[lp].val + tr[rp].val;
}

void build(int p, int l, int r) {
	if (l == r) {
		tr[p].val = {a[id[l]], a[id[l]]};
		return ;
	}
	int mid = (l + r) >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

void change(int p, int l, int r, int x, int d) {
	if (l == r) {
		tr[p].val = {d, d};
		return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) change(lp, l, mid, x, d);
	else change(rp, mid + 1, r, x, d);
	pushup(p);
}

info query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tr[p].val;
	int mid = (l + r) >> 1;
	if (L > mid) return query(rp, mid + 1, r, L, R);
	else if (R <= mid) return query(lp, l, mid, L, R);
	else return query(lp, l, mid, L, R) + query(rp, mid + 1, r, L, R);
}

info query(int u, int v) {
	info ans{(int)-1e9, 0};
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			ans = ans + query(1, 1, n, l[top[v]], l[v]);
			v = fa[top[v]];
		} else {
			ans = ans + query(1, 1, n, l[top[u]], l[u]);
			u = fa[top[u]];
		}
	}
	if (dep[u] <= dep[v]) ans = ans + query(1, 1, n, l[u], l[v]);
	else ans = ans + query(1, 1, n, l[v], l[u]);
	return ans;
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
	if (~hs[u]) dfs2(hs[u], t);
	for (auto v : e[u]) {
		if (v != fa[u] && v != hs[u]) {
			dfs2(v, v);
		}
	}
	r[u] = tot;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		char op[10];
		scanf("%s%d%d", op, &u, &v);
		if (op[0] == 'C') {
			change(1, 1, n, l[u], v);
		} else {
			info ans = query(u, v);
			if (op[1] == 'M') {
				printf("%d\n", ans.maxv);
			} else {
				printf("%d\n", ans.sum);
			}
		}
	}
}

int main() {
	solve();
	return 0;
}