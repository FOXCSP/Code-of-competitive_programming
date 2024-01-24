#include <bits/stdc++.h>

using namespace std;

const int N = 200010, inf = (1 << 30);

#define lp (p<<1)
#define rp (p<<1|1)

int n, q;
int a[N], ans[N];

struct seg {
	int minv;
} tr[N << 2];

void pushup(int p) {
	tr[p].minv = min(tr[lp].minv, tr[rp].minv);
}

void build(int p, int l, int r) {
	if (l == r) {
		tr[p].minv = inf;
	} else {
		int mid = l + r >> 1;
		build(lp, l, mid), build(rp, mid + 1, r);
		pushup(p);
	}
}

void modify(int p, int l, int r, int x, int v) {
	if (l == r) {
		tr[p].minv = v;
	} else {
		int mid = l + r >> 1;
		if (x <= mid) modify(lp, l, mid, x, v);
		if (x > mid) modify(rp, mid + 1, r, x, v);
		pushup(p);
	}
}

int query(int p, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return tr[p].minv;
	int mid = l + r >> 1;
	int val = inf;
	if (ql <= mid)  val = min(val, query(lp, l, mid, ql, qr));
	if (qr > mid) val = min(val, query(rp, mid + 1, r, ql, qr));
	return val; 
} 

vector<array<int, 4>> event;

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		event.push_back({-a[i], 0, i, 0});
	}
	build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		event.push_back({-x, i, l, r});
	}
	sort(event.begin(), event.end());
	for (auto evt : event) {
		if (evt[1] == 0) modify(1, 1, n, evt[2], -evt[0]);
		else ans[evt[1]] = query(1, 1, n, evt[2], evt[3]);
	}
	for (int i = 1; i <= n; i++)
		cout << (ans[i] == inf ? -1 : ans[i])<< '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}