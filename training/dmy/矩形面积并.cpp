#include <bits/stdc++.h>
// #define int long long

#define lp (p<<1)
#define rp (p<<1|1)

using namespace std;
using ll = long long;

const int N = 200010;

int n, k;
vector<int> vx;
vector<array<int, 4>> event;

struct info {
	int minv;
	ll mincnt;
	info operator + (const info& B) const {
		int a = min(minv, B.minv);
		ll b = mincnt;
		if (minv == B.minv) b += B.mincnt;
		else if (minv > B.minv) b = B.mincnt;
		return (info){a, b};
	}
};

struct seg{
	info val;
	int t;
}tr[N * 8];

void pushup(int p) {
	tr[p].val = tr[lp].val + tr[rp].val;
}

void settag(int p, ll t) {
	tr[p].val.minv += t;
	tr[p].t += t;
}

void pushdown(int p) {
	if (tr[p].t != 0) {
		settag(lp, tr[p].t);
		settag(rp, tr[p].t);
		tr[p].t = 0;
	}
}

void build(int p, int l, int r) {
	tr[p].t = 0;
	if (l == r) {
		tr[p].val = {0, vx[r] - vx[r - 1]};
		return ;
	}
	int mid = l + r >> 1;
	build(lp, l, mid), build(rp, mid + 1, r);
	pushup(p);
}

void modify(int p, int l, int r, int ql, int qr, ll v) {
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

int find(int k) {
	return lower_bound(vx.begin(), vx.end(), k) - vx.begin();
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		vx.push_back(x1);
		vx.push_back(x2);
		event.push_back({y2, -1, x1, x2});
		event.push_back({y1, 1, x1, x2});
	}
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	sort(event.begin(), event.end());


	int m = vx.size() - 1;
	build(1, 1, m); // [0-m]的线段树
	int maxlen = tr[1].val.mincnt;
	ll ans = 0, pre = event[0][0];

	for (auto evt : event) {
		ll res = maxlen;
		if (tr[1].val.minv == 0) res = maxlen - tr[1].val.mincnt;
		ans = ans + (ll)res * (evt[0] - pre);
		pre = evt[0];
		int x1 = find(evt[2]) + 1;
		int x2 = find(evt[3]);
		if (x1 <= x2) {
			modify(1, 1, m, x1, x2, evt[1]);
		}
	}
	cout << ans << '\n';
}
/*
2
1 1000000000 1 1000000000
1 1000000000 1 1000000000
*/

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}