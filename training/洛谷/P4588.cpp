#include <bits/stdc++.h>
#define int long long
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
using ll = long long;

const int N = 100010;
int mod, n, q;

struct Seg {
	int l, r, dat;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define dat(x) tree[x].dat
} tree[N * 4];

void pushup(int p) {
	dat(p) = (dat(lp) * dat(rp)) % mod;
}

void build(int p, int l, int r) {
	l(p) = l, r(p) = r;
	if(l == r) { dat(p) = 1; return ;}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

void change(int p, int x, int v) {
	if(l(p) == r(p)) {
		dat(p) = v;
		return ;
	}
	int mid = l(p) + r(p) >> 1;
	if(x <= mid) change(lp, x ,v);
	else if(x > mid) change(rp, x, v);
	pushup(p);
}
int query(int p, int l, int r) {
	return dat(p);
}
void solve() {
	cin >> q >> mod;
	build(1, 1, q);
	for(int i = 1;i <= q; i ++) {
		int op, x;
		cin >> op >> x;
		if(op == 1) {
			change(1, i, x % mod);
			cout << query(1, 1, n) % mod << '\n';
		}
		else {
			change(1, x, 1);
			cout << query(1, 1, n) % mod << '\n';
		}
	}
}

signed main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	while(t --) solve();
	return 0;
}