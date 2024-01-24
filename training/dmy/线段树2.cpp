#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define lp (p<<1)
#define rp (p<<1|1)

const int N = 200010;
int n, m;
int a[N];

struct seg {
	ll mal, mar, mmid, sum, val;
	seg operator + (const seg & B) const { // add left with the right
		seg res;
		res.sum = sum + B.sum;
		res.mal = mal > sum + B.mal ? mal : sum + B.mal;
		res.mar = B.mar > B.sum + mar ? B.mar : B.sum + mar;
		res.val = max({val, B.val, mar + B.mal});
		return res;
	}
} tr[N << 2];

void update(int p) {
	tr[p] = tr[lp] + tr[rp];
}

void build(int p, int l, int r) {
	if (l == r) {
		tr[p] = {a[l], a[l], a[l], a[l], a[l]};
		return ;
	}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	update(p);
}

void modify(int p, int l, int r, int x, int v) {
	if (l == r) {
		tr[p] = {v, v, v, v, v};
		return ;
	}
	int mid = l + r >> 1;
	if (x <= mid) modify(lp, l, mid, x, v);
	if (x > mid) modify(rp, mid + 1, r, x, v);
	update(p);
}

seg query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tr[p];
	int mid = l + r >> 1;
	if (L > mid) return query(rp, mid + 1, r, L, R);
	else if (R <= mid) return query(lp, l, mid, L, R);
	else return query(lp, l, mid, L, R) + query(rp, mid + 1, r, L, R);
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
			auto t = query(1, 1, n, a, b);
			cout << t.val << '\n';
		}
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return (0-0);
}