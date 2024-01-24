#include <bits/stdc++.h>
#define int long long

#define lp (p<<1)
#define rp (p<<1|1)

using namespace std;

const int N = 100010;
int n, m, mod;
int a[N];

int qmi(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1)
			res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

struct tag {
	int add, mul;
	tag operator + (const tag & B) const {
		// tag res;
		int a = mul * B.mul % mod;
		int b = add * B.mul % mod + B.add % mod;
		return (tag){b, a};
	}
};

struct seg {
	int v, v2;
	int l, r;
	tag t;
} tr[N << 4]; 

void settag(int p, tag t) {
	int d = tr[p].r - tr[p].l + 1;
	tr[p].v2 = (tr[p].v2 % mod * t.mul % mod * t.mul % mod + t.add % mod * t.add % mod * d % mod + 2 * t.add % mod * t.mul % mod * tr[p].v % mod) % mod;
	tr[p].v = tr[p].v * t.mul % mod + d * t.add % mod;
	tr[p].t = tr[p].t + t;
}

void pushup(int p) {
	tr[p].v = tr[lp].v + tr[rp].v % mod;
	tr[p].v2 = tr[lp].v2 + tr[rp].v2 % mod;
}

void pushdown(int p) {
	if (tr[p].t.add != 0 || tr[p].t.mul != 1) {
		settag(lp, tr[p].t);
		settag(rp, tr[p].t);
		tr[p].t = {0, 1};
	}
}

void build(int p, int l, int r) {
	tr[p].l = l, tr[p].r = r;
	tr[p].t = {0, 1};
	if (l == r) {
		tr[p].v = a[l];
		tr[p].v2 = a[l] * a[l];
	} else {
		int mid = l + r >> 1;
		build(lp, l, mid), build(rp, mid + 1, r);
		pushup(p);
	}
}

void modifyadd(int p, int l, int r, int ql, int qr, int d) {
	if (ql <= l && r <= qr) {
		settag(p, (tag){d, 1});
		return ;
	}
	pushdown(p);
	int mid = l + r >> 1;
	if (ql <= mid) modifyadd(lp, l, mid, ql, qr, d);
	if (qr > mid) modifyadd(rp, mid + 1, r, ql, qr, d);
	pushup(p);
}

void modifymul(int p, int l, int r, int ql, int qr, int d) {
	if (ql <= l && r <= qr) {
		settag(p, (tag){0, d});
		return ;
	}
	pushdown(p);
	int mid = l + r >> 1;
	if (ql <= mid) modifymul(lp, l, mid, ql, qr, d);
	if (qr > mid) modifymul(rp, mid + 1, r, ql, qr, d);
	pushup(p);
}

pair<int, int> operator + (const pair<int, int> a, const pair<int, int> b) {
	return {(a.first + b.first) % mod, (a.second + b.second) % mod};
}
pair<int,int> query(int p, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return {tr[p].v, tr[p].v2};
	}
	int mid = l + r >> 1;
	pair<int,int> val = {0, 0};
	if (ql <= mid) val = val + query(lp, l, mid, ql, qr);
	if (qr > mid) val = val + query(rp, mid + 1, r, ql, qr);
	return val;
}

void debug(int p, int l, int r) {
	if (l == r) {
		cout << tr[p].v << " ";
	} else {
		int mid = l + r >> 1;
		debug(lp, l, mid), debug(rp, mid + 1, r);
	}
}

void solve() {
	cin >> n >> m >> mod;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		int op, l, r;
		cin >> op >> l >> r;
		if (op != 3) {
			int v; cin >> v;
			if (op == 1) {
				modifyadd(1, 1, n, l, r, v);
			} else {
				modifymul(1, 1, n, l, r, v);
			}
		} else {
			auto t = query(1, 1, n, l, r);
			cout << ((t.first * t.first - t.second + mod) % mod) * qmi(2, mod - 2)  % mod<< '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin >> _; while(_--) solve();
	return 0;
}