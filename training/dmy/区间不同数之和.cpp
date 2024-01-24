#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200010;

int n, q;
int a[N], pos[N];
ll c[N], ans[N];
vector<pair<int, int>> qu[N];

void modify(int x, int v) {
	for (; x <= n; x += x & (-x)) c[x] += v;
}
ll query(int x) {
	ll s = 0;
	for (; x; x -= x & (-x)) s += c[x];
	return s;
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; i++) {
		int l, r; cin >> l >> r;
		qu[r].push_back({l, i});
	}
	for (int r = 1; r <= n; r++) {
		int q = pos[a[r]];
		modify(q + 1, a[r]);
		modify(r + 1, -a[r]);
		pos[a[r]] = r;
		for (auto x : qu[r]) {
			ans[x.second] = query(x.first);
		}
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n'; 
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}