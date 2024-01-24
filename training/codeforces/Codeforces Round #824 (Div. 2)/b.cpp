#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];
void solve() {
	int n; cin >> n;
	int mn = 1e9;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		int t = a[i];
		int k = 2 * mn - 1, p = t / k;
		ans += p;
		if(p * k == t) ans --;
	}
	cout << ans << '\n';
}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T; while(T --) solve();
	return 0;
}