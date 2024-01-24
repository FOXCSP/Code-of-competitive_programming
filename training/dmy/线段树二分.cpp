#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)

using namespace std;

const int N = 200010;

int a[N], n, m;
struct seg {
	int maxv;
} tr[N << 2];

void pushup(int p) {
	tr[p].maxv = max(tr[lp].maxv, tr[rp].maxv);
} 

void build(int p, int l, int r) {
	if (l == r) {
		tr[p].maxv = a[l];
		return ;
	}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

void modify(int p, int l, int r, int x, int v) {
	if (l == r) {
		tr[p].maxv = v;
		return ;
	}
	int mid = l + r >> 1;
	if (x > mid) modify(rp, mid + 1, r, x, v);
	if (x <= mid) modify(lp, l, mid, x, v);
	pushup(p);
}

int query(int p, int l, int r, int ql, int qr, int d) {
	// if (l > qr || r < ql) return -1;
	if (l == r) {
		return l;
	}
	int mid = l + r >> 1;
	int val = -1;
	if (tr[lp].maxv >= d && ql <= mid) {
		val = query(lp, l, mid, ql, qr, d);
		if (val == -1) {
			if (tr[rp].maxv >= d && qr > mid) val = query(rp, mid + 1, r, ql, qr, d);
		}
		else return val;
	}
	else if (tr[rp].maxv >= d && qr > mid) return query(rp, mid + 1, r, ql, qr, d);
	return val;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	build(1, 1, n);
	while (m --) {
		int op, a, b; cin >> op >> a >> b;
		if (op == 1) {
			modify(1, 1, n, a, b);
		}
		else {
			int d; cin >> d;
			cout << query(1, 1, n, a, b, d) << '\n';
		}	
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}