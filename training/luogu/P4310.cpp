#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[35];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, ans = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int res = 0;
		for (int i = 0; i <= 30; i++) {
			if (x >> i & 1)
				res = max(res, dp[i] + 1);
		} 
		for (int i = 0; i <= 30; i++) {
			if (x >> i & 1)
				dp[i] = max(dp[i], res);
		}
		ans = max(ans, res);
	}
	cout << ans << '\n';
	return 0;
} 
