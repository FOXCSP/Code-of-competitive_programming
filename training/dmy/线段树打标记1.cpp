#include <bits/stdc++.h>

#define lp (p<<1)
#define rp (p<<1|1)

using namespace std;
using ll = long long;

const int N = 200010;

int n, m;
struct seg {
	ll tag, maxv;
} tr[N << 2];

seg operator + (const seg &l, const seg &r) {
	seg res;
	res.maxv = max(l.maxv, r.maxv);
	res.tag = 0;
	return res;
}

void make_tag(int p, int v) {
	tr[p].maxv += v;
	tr[p].tag += v;
}

void pushup(int p) {
	tr[p] = tr[lp] + tr[rp];
}

void pushdown(int p) {
	if (tr[p].tag) {
		tr[lp].maxv += tr[p].tag;
		tr[rp].maxv += tr[p].tag; 
		tr[lp].tag += tr[p].tag;
		tr[rp].tag += tr[p].tag;
		tr[p].tag = 0;
	}
}

void build(int p, int l, int r) {
	if (l == r) {
		cin >> tr[p].maxv;
		return;
	}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

void modify(int p, int l, int r, int L, int R, ll d) {
	if (L <= l && r <= R) {
		make_tag(p, d);
		return ;
	}
	pushdown(p);
	int mid = l + r >> 1;
	if (L <= mid) modify(lp, l, mid, L, R, d);
	if (R > mid) modify(rp, mid + 1, r, L, R, d);
	pushup(p);
}

ll query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return tr[p].maxv;
	}
	pushdown(p);
	int mid = l + r >> 1;
	ll val = 0;
	if (L <= mid) val = max(val, query(lp, l, mid, L, R));
	if (R > mid) val = max(val, query(rp, mid + 1, r, L, R));
	return val;
}

void solve () {
	cin >> n >> m;
	build(1, 1, n);
	while (m --) {
		int op, l, r;
		cin >> op >> l >> r;
		if (op == 1) {
			int d; cin >> d;
			modify(1, 1, n, l, r, d);
		}
		else {
			ll t = query(1, 1, n, l, r);
			cout << t << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}