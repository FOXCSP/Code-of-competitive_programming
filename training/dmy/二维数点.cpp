#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
int c[N], n, q, m, ans[N];

void modify(int x, int v) {
	for (; x <= m; x += x & (-x)) c[x] += v;
}
int query(int x) {
	int s = 0;
	for (; x; x -= x & (-x))
		s += c[x];
	return s;
}

vector<int> vx;
vector<array<int, 4>> event;

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vx.push_back(x);
		event.push_back({y, 0, x});
	}
	// 将事件拆分, 因为我们将询问离线, 所以对一次查询我们可以将四个过程拆开
	for (int i = 1; i <= q; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		event.push_back({y2, 2, x2, i});
		event.push_back({y1 - 1, 2, x1 - 1, i});
		event.push_back({y2, 1, x1 - 1, i});
		event.push_back({y1 - 1, 1, x2, i});
	}
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	sort(event.begin(), event.end()); // 将事件按y排序
	m = vx.size();
	for (auto evt : event) {
		if (evt[1] == 0) {
			int y = lower_bound(vx.begin(), vx.end(), evt[2]) - vx.begin() + 1;
			modify(y, 1);
		} else {
			int y = upper_bound(vx.begin(), vx.end(), evt[2]) - vx.begin();
			int tmp = query(y);
			if (evt[1] == 1) ans[evt[3]] -= tmp;
			else ans[evt[3]] += tmp;
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}