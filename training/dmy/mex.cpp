#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)

using namespace std;

const int N = 200010;

int n, m;
int pos[N], a[N], ans[N];
vector<pair<int,int>> qu[N];

struct seg {
	int minv;
} tr[N << 4];

void pushup(int p) {
	tr[p].minv = min(tr[lp].minv, tr[rp].minv);
}

void modify(int p, int l, int r, int x, int v) {
	if (l == r) {
		tr[p].minv = v;
	} else {
		int mid = l + r >> 1;
		if (x > mid) modify(rp, mid + 1, r, x, v);
		else if (x <= mid) modify(lp, l, mid, x, v);
		pushup(p);
	}
}

int query(int p, int l, int r, int x) { // query min[pos[id] < ] id
	if (l == r) return l;
	int mid = l + r >> 1;
	if (tr[lp].minv < x) return query(lp, l, mid, x);
	else return query(rp, mid + 1, r, x);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = min(a[i], n + 1);
	}

	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		qu[r].push_back({l, i});
	}

	for (int r = 1; r <= n; r++) {
		// pos[x] 表示x最后出现的位置, 所以要将a[x]加上r
		modify(1, 0, n + 1, a[r], r);
		for (auto que : qu[r]) {
			ans[que.second] = query(1, 0, n + 1, que.first);
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << ans[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}