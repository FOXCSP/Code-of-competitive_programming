#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, x, y; cin >> n >> x >> y;
	string a, b; cin >> a >> b;
	int cnt = 0;
	for(int i = 0;i < n; i ++) if(a[i] != b[i]) cnt ++;
	if(cnt & 1) {
		cout << "-1\n"; return ;
	}

	int res = 0;
	for(int i = 0; i < n - 1; i ++) {
		if(a[i] != b[i] && a[i + 1] != b[i + 1]) {
			res ++; i ++;
		}
	}

	int ans = 0;
	if(res == 1 && cnt == 2) ans += min(x, 2 * y);
	else ans += y * res;

	res = cnt - 2 * res;
	ans += res/2 * y;
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin >> _; while(_--) solve();
	return 0;
}