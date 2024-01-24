#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200010;
ll c[N], n, a[N], dp[N], ans;

void modify(ll x, ll v) {
	for (; x <= n; x += x & (-x)) c[x] = max(c[x], v);
}

ll query(ll x) {
	ll s = 0;
	for (; x; x -= x & (-x)) s = max(s, c[x]);
	return s;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = a[i] + query(a[i] - 1);
		modify(a[i], dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}