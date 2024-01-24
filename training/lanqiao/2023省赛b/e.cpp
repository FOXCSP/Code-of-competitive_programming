#include <bits/stdc++.h>
#define int long long
#define vec vector
#define se second
#define fi first
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;

const int N = 10010, inf = 1e9;

void solve (int Case) {
	int n;
	cin >> n;
	vec<int> a(n+1,0), cnt(n+1,0), st(100, 0);
	vec<vec<int> > dp(n+1, vec<int> (110, inf));
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int t = 0;
		t = (s[0] - '0');
		if (SZ(s) > 1) t = t * 10 + (s.back() - '0');
		cnt[i] = t;
	}
	
	dp[1][cnt[1]] = 0;
	dp[1][0] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 100; j++) {
			if (cnt[i] < 10) {
				if (cnt[i] == j%10) dp[i][cnt[i]] = min(dp[i][cnt[i]], dp[i-1][j]);
				dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
			} else {
				if (j%10 == cnt[i]/10) {
					dp[i][cnt[i]] = min(dp[i][cnt[i]], dp[i-1][j]);
					dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
				} else {
					dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
				}
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i < 100; i++) ans = min(ans, dp[n][i]);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
	for (int i=1; i<=_;i++) {
		solve(i);
	}
	return 0;
}
