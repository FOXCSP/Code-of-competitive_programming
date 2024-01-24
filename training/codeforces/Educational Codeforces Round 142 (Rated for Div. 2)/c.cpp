#include <bits/stdc++.h>
#define fi first
#define se second
#define all(X) X.begin(), X.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), pos(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	int ans = n / 2;
	int res = 0, l = 1, r = 1;
	for (;l <= n && r <= n;) {
		r = l + 1;
		while (r <= n && pos[r] > pos[r - 1]) r++;
		r--;
		res = max(n - r, l - 1);
		ans = min(ans, res);
		l = r + 1;
	}
	cout << ans << '\n';
}

int main() {
	int _; cin >> _;
	while (_--)
	solve();
	return 0;
}