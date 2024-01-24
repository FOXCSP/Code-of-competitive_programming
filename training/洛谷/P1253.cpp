#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int N = 1000010, null = 1e18;
int n, m;

struct seg {
	int l, r;
	ll mx, add, to;
	#define lp (p<<1)
	#define rp (p<<1|1)
	#define mx(x) tr[x].mx
	#define add(x) tr[x].add
	#define to(x) tr[x].to
	#define l(x) tr[x].l
	#define r(x) tr[x].r
} tr[N * 8];

void pushup(int p) {
	mx(p) = max(mx(lp), mx(rp));
}

void build(int p, int l, int r) {
	l(p) = l, r(p) = r;
	add(p) = 0, to(p) = null;
	if(l == r) { cin >> mx(p); return ;}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

void pushdown(int p) {
	if(to(p) != null) {
		mx(lp) = to(lp) = to(p);
		mx(rp) = to(rp) = to(p);
		add(lp) = add(rp) = 0;
		to(p) = null;
	}
	else if(add(p)) {
		mx(lp) += add(p);
		mx(rp) += add(p);
		if(to(lp) != null) to(lp) += add(p); else add(lp) += add(p);
		if(to(rp) != null) to(rp) += add(p); else add(rp) += add(p);
		add(p) = 0;
	}
}

void modify(int p, int l, int r, int x, int tag) {
	if(l > r(p) || r < l(p)) return ;
	pushdown(p);
	if(l <= l(p) && r(p) <= r) {
		if(tag == 1) {
			mx(p) = to(p) = x, add(p) = 0;
		}
		else {
			mx(p) += x;
			if(to(p) != null) to(p) += x; else add(p) += x;
		}
		return ;
	}
	modify(lp, l, r, x, tag), modify(rp, l, r, x, tag);
	pushup(p); 
}

ll query(int p, int l, int r) {
	if(l > r(p) || r < l(p)) return -1 * null;
	pushdown(p);
	if(l <= l(p) && r(p) <= r) {
		return mx(p);
	}
	return max(query(rp, l, r), query(lp, l, r));
}

void debug(int p, int l, int r) {
	if(l == r) {cout << mx(p) << " "; return ;}
	int mid = l + r >> 1;
	debug(lp, l, mid), debug(rp, mid + 1, r);
}

void solve() {
	cin >> n >> m;
	build(1, 1, n);
	while(m --) {
		int op, l, r; cin >> op >> l >> r;
		if(op != 3) {
			int x; cin >> x;
			modify(1, l, r, x, op);
			// debug(1, 1, n);
			// cout << "----\n";
		}
		else {
			cout << query(1, l, r) << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(nullptr);
	solve();
	return 0;
}