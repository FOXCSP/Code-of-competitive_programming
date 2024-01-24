#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
int n, m;

#define lp (p<<1)
#define rp (p<<1|1)

struct seg {
	int minv, minvcnt;
	seg operator + (const seg& B) const {
		seg res;
		res.minv = min(B.minv, minv);
		if (minv == B.minv) res.minvcnt = minvcnt + B.minvcnt;
		else res.minvcnt = minv < B.minv ? minvcnt : B.minvcnt;
		return res;
	}
} tr[N << 2]; 

void update(int p) {
	tr[p] = tr[lp] + tr[rp];
}

void build(int p, int l, int r) {
	if (l == r) {
		cin >> tr[p].minv; tr[p].minvcnt = 1;
		return ;
	}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	update(p);
}
// modify[x] -> v
void modify(int p, int l, int r, int x, int v) {
	if (l == r) {
		tr[p].minv = v;
		return ;
	}
	int mid = l + r >> 1;
	if (x <= mid) modify(lp, l, mid, x, v);
	if (x > mid) modify(rp, mid + 1, r, x, v);
	update(p);
}
// query[L, R]
seg query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tr[p];
	int mid = l + r >> 1;
	if (L > mid) return query(rp, mid + 1, r, L, R);
	else if (R <= mid) return query(lp, l, mid, L, R);
	else return query(lp, l, mid, L, R) + query(rp, mid + 1, r, L, R);
}

void solve() {
	cin >> n >> m;
	build(1, 1, n);
	while (m --) {
		int op, a, b; cin >> op >> a >> b;
		if (op == 1) {
			modify(1, 1, n, a, b);
		}
		else {
			auto t = query(1, 1, n, a, b);
			cout << t.minv << " " << t.minvcnt << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}