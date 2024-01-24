#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T> 
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
const int N = 200010;
const ll mod = 1000000007;
int n, m;
int a[N];
//db Cos[N], Sin[N];

struct seg {
	db sin, cos;
	ll tg;
} tr[N * 8];

void pushup(int p) {
	tr[p].sin = tr[lp].sin + tr[rp].sin;
	tr[p].cos = tr[lp].cos + tr[rp].cos;
}

void settag(int p, int tg) {
	db sinx = tr[p].sin, cosx = tr[p].cos;
	tr[p].sin = sinx * Cos[tg] + cosx * Sin[tg];
	tr[p].cos = cosx * Cos[tg] - sinx * Sin[tg];
	tr[p].tg += tg; 
}

void pushdown(int p) {
	if (tr[p].tg != 0) {
		settag(lp, 1.0 * tr[p].tg);
		settag(rp, 1.0 * tr[p].tg);
		tr[p].tg = 0;
	}
}

void build(int p, int l, int r) {
	if (l == r) {
		tr[p].sin = sin(1.0 * a[l]);
		tr[p].cos = cos(1.0 * a[l]);
	} else {
		int mid = (l + r) / 2;
		build(lp, l, mid);
		build(rp, mid + 1, r);
		pushup(p); 
	}
}

void modify(int p, int l, int r, int ql, int qr, int d) {
	pushdown(p);
	if (ql <= l && r <= qr) {
		settag(p, 1.0 * d);
	} else {
		int mid = (l + r) / 2;
		if (ql <= mid) modify(lp, l, mid, ql, qr, d);
		if (qr > mid) modify(rp, mid + 1, r, ql, qr, d);
		pushup(p);
	}
}

db query(int p, int l, int r, int ql, int qr) {
	pushdown(p);
	if (ql <= l && r <= qr)
		return tr[p].sin;
	int mid = (l + r) / 2;
	if (qr <= mid) return query(lp, l, mid, ql, qr);
	else if (ql > mid) return query(rp, mid + 1, r, ql, qr);
	else return query(lp, l, mid, ql, qr) + query(rp, mid + 1, r, ql, qr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	
	for (int i = 0; i <= 200000; i++) 
		Sin[i] = sin(1.0 * i),
		Cos[i] = cos(1.0 * i);
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	build(1, 1, n);
	cin >> m;
	
	for (; m--; ) {
		int op, l, r, v;
		cin >> op >> l >> r;
		if (op == 1) {
			cin >> v;
			modify(1, 1, n, l, r, v);
		} else {
			auto ans = query(1, 1, n, l, r);
			cout << fixed << setprecision(1) << ans << '\n';
		}
	}
	return 0;
}

