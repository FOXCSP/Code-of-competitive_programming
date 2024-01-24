#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
const int N = 100010, M = 10010;

vector<int> vx;
int n, m;
int a[N], root[N], idx;
struct seg {
	int cnt;
	int l, r;
}tr[N * 4 + N * 17];

int build(int l, int r) {
	int p = ++idx;
	tr[p] = {0, l, r};
	int mid = l + r >> 1;
	tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
	return p;
}

int insert(int q, int l, int r, int x) {
	int p = ++idx;
	tr[p] = tr[q];
	if (l == r) {
		tr[q].cnt++;
		return q;
	}
	int mid = l + r >> 1;
	if (x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
	else tr[q].r = insert(tr[p].r, mid + 1, r, x);
	tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
	return q;
}


int find(int x) {
	return lower_bound(vx.begin(), vx.end(), x) - vx.begin();
}

int query(int q, int p, int l, int r, int k) {
	if (l == r) return r;
	int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
	int mid = l + r >> 1;
	if (k <= cnt) return query(tr[q].l, tr[p].l, l, mid, k);
	else return query(tr[q].r, tr[p].r, mid + 1, r, k);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vx.push_back(a[i]);
	}
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	root[0] = build(0, vx.size());

	for (int i = 1; i <= n; i++) 
		root[i] = insert(root[i - 1], 0, vx.size() - 1, find(a[i]));

	while (m--) {
		int l, r, k;
		cin >> l >> r >> k;
		int t = query(root[r], root[l - 1], 0, vx.size() - 1, k);
		cout << vx[t] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}