#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

const int N = 1010;
int dp[N][N], mn1[N], mn2[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s, t;
	int n, m;
	cin >> s >> t;

	n = SZ(s), m = SZ(t);
	s = "#" + s;
	t = "#" + t;

	memset(dp, 0x3f, sizeof dp);
	memset(mn1, 0x3f, sizeof mn1);
	memset(mn2, 0x3f, sizeof mn2);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= min(i, m); j++) {
			if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j]);
		}
	cout << dp[n][m] << '\n';
	return 0;
} 
