#include <bits/stdc++.h>

#define lp (p<<1)
#define rp (p<<1|1)

using namespace std;
using ll = long long;

const int N = 200010;
const ll mod = 1e9 + 7;
int n, m;
struct tag {
	ll mul, add;
	tag operator + (const tag & B) const {
		return (tag){mul * B.mul % mod, (add * B.mul + B.add) % mod};
	}
};

struct seg {
	tag t;
	ll sum;
	int sz;
} tr[N << 2]; 

void make_tag(int p, tag t) { // 将p的sum处理完后打tag
	tr[p].sum = (tr[p].sum * t.mul + tr[p].sz * t.add) % mod;
	tr[p].t = tr[p].t + t;
}

void pushup(int p) {
	tr[p].sum = (tr[lp].sum + tr[rp].sum) % mod;
}

void pushdown(int p) {
	if (tr[p].t.mul != 1 || tr[p].t.add != 0) { // 存在标记
		make_tag(lp, tr[p].t);
		make_tag(rp, tr[p].t);
		tr[p].t = {1, 0};
	}
}

void build(int p, int l, int r) {
	tr[p].sz = r - l + 1;
	tr[p].t = {1, 0};
	if (l == r) {
		cin >> tr[p].sum;
		return ;
	}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

void modify(int p, int l, int r, int L, int R, tag t) {
	if (L <= l && r <= R) {
		make_tag(p, t);
		return ;
	}
	pushdown(p);
	int mid = l + r >> 1;
	if (L <= mid) modify(lp, l, mid, L, R, t);
	if (R > mid) modify(rp, mid + 1, r, L, R, t);
	pushup(p);
}

ll query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) {

		return tr[p].sum;
	}
	pushdown(p);
	int mid = l + r >> 1;
	ll val = 0;
	if (L <= mid) val = (val + query(lp, l, mid, L, R)) % mod;
	if (R > mid) val = (val + query(rp, mid + 1, r, L, R)) % mod;
	return val;
}

void solve() {
	cin >> n >> m;
	build(1, 1, n);
	while (m --) {
		int op, l, r;
		cin >> op >> l >> r;
		if (op != 4) {
			ll d; cin >> d;
			if (op == 1) modify(1, 1, n, l, r, (tag){1, d});
			else if (op == 2) modify(1, 1, n, l, r, (tag){d, 0});
			else modify(1, 1, n, l, r, (tag){0, d});
		}
		else {
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false),cin.tie(nullptr);
	solve();
	return 0;
}