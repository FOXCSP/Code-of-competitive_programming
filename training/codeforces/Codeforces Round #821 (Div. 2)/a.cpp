#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[110], b[110];

void solve() {
	int n, k;
	cin >> n >> k;
	memset(b, 0, sizeof b);
	for(int i = 1;i <= n; i ++) {
		cin >> a[i];
		b[i % k] = max(b[i % k], a[i]);
	}
	ll ans = 0;
	for(int i= 0;i < k;i  ++) ans += b[i];
	cout << ans << endl;
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}