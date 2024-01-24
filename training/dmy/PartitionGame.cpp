#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)

using namespace std;

const int N = 35010;

int n, m, a[N], k, f[N], last[N], pre[N];
struct seg {
	int val, t;
} tr[N << 4];

void settag(int p, int t) {
	tr[p].val += t;
	tr[p].t += t;
}

void pushup(int p) {
	tr[p].val = min(tr[lp].val, tr[rp].val);
}

void build(int p, int l, int r) {
	tr[p].t = tr[p].val = 0;
	if (l == r) {
		tr[p].val = f[l];
		return ;
	}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

void pushdown(int p) {
	if (tr[p].t) {
		settag(lp, tr[p].t); 
		settag(rp, tr[p].t);
		tr[p].t = 0;
	}
}

void modify(int p, int l, int r, int ql, int qr, int v) {
	if (ql <= l && r <= qr) {
		settag(p, v);
		return ;
	}
	pushdown(p);
	int mid = l + r >> 1;
	if (ql <= mid) modify(lp, l, mid, ql, qr, v);
	if (qr > mid) modify(rp, mid + 1, r, ql, qr, v);
	pushup(p);
}

int query(int p, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return tr[p].val;
	}
	pushdown(p);
	int mid = l + r >> 1;
	int val = 1 << 30;
	if (ql <= mid) val = min(val, query(lp, l, mid, ql, qr));
	if (qr > mid) val = min(val, query(rp, mid + 1, r, ql, qr));
	return val;
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		last[i] = pre[a[i]];
		pre[a[i]] = i;
	}
	f[0] = 0;
	for (int i = 1; i <= n; i++) f[i] = 1 << 30;
	for (int j = 1; j <= k; j++) {
		build(1, 0, n);
		for (int i = 1; i <= n; i++) {
			if (last[i]) modify(1, 0, n, 0, last[i] - 1, i - last[i]);
			f[i] = query(1, 0, n, 0, i - 1);
			// cout << i << " " << j << " " << f[i] << '\n';
		}
	}
	cout << f[n] << '\n';
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	solve();
	return 0;
}