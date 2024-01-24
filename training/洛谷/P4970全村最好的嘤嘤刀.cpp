#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100010;

struct seg {
	int mx, id, ok, lz;
} tr[N << 4];

int n, m;

#define lp (p<<1)
#define rp (p<<1|1)


seg get(seg a, seg b) {
	if(a.ok && !b.ok) return a;
	if(!a.ok && b.ok) return b;
	if(a.mx > b.mx) return a;
	else return b;
}

void pushup(int p) {
	tr[p] = get(tr[lp], tr[rp]);
}

void pushdown(int p) {
	if(tr[p].lz) {
		tr[lp].mx += tr[p].lz;
		tr[rp].mx += tr[p].lz;
		tr[lp].lz += tr[p].lz;
		tr[rp].lz += tr[p].lz;
 		tr[p].lz = 0;
	}
}

void build(int p, int l, int r) {
	if(l == r) {
		cin >> tr[p].mx; tr[p].id = l;
		// , tr[p].lz = 0, 
		tr[p].ok = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

void modify(int p, int l, int r, int a, int b, int op) {
	if(l == r) {
		tr[p].mx = b, tr[p].ok = op;
		return ;
	}
	pushdown(p);
	int mid = l + r >> 1;
	if(a > mid) modify(rp, mid + 1, r, a, b, op);
	if(a <= mid) modify(lp, l, mid, a, b, op);
	pushup(p);
}

void add(int p, int l, int r, int L, int R, int val) {
	if(L <= l && r <= R) {
		tr[p].mx += val; tr[p].lz += val;
		return ;
	}
	pushdown(p);
	int mid = l + r >> 1;
	if(L <= mid) add(lp, l, mid, L, R, val);
	if(R > mid) add(rp, mid + 1, r, L, R, val);
	pushup(p);
}

seg query(int p, int l, int r, int L, int R) {
	if(L <= l && r <= R)	return tr[p];
	int mid = l + r >> 1;
	pushdown(p);
	seg s = {(int)(-1e9), 0, 0, 0};
	if(L <= mid) s = get(s, query(lp, l, mid, L, R));
	if(R > mid) s = get(s, query(rp, mid + 1, r, L, R));
	return s;
}

void solve() {
	cin >> n >> m;
	build(1, 1, n);
	int ans = 0;
	while(m --) {
		int op; cin >> op;
		if(op == 1) {
			int a, b; cin >> a >> b;
			auto t = query(1, 1, n, a, a);
			modify(1, 1, n, a, b - t.mx, 1);
		}
		else if(op == 2) {
			int l, r; cin >> l >> r;
			auto t = query(1, 1, n, l, r);
			modify(1, 1, n, t.id, 0, 0);
			cout << t.mx << "\n";
			ans += t.mx;
		}
		else {
			int l, r, val; cin >> l >> r >> val;
			add(1, 1, n, l, r, val);
		}
	}
	if(ans < 10000) cout << "QAQ\n";
	else if(ans < 10000000) cout << "Sakura\n";
	else cout << "ice\n";
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}