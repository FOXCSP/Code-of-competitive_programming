#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 110;
int dp[N][N], a[N][N], n, m, pre[N][N];

void out(int x, int y) {
	if (x > 1) out(x - 1, pre[x][y]);
	cout << y << " ";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -0x3f, sizeof dp);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= m - n + 1; i++)
		dp[1][i] = a[1][i];
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			for (int t = 1; t < j; t++) {
				if (dp[i][j] < dp[i - 1][t] + a[i][j]) {
					dp[i][j] = dp[i - 1][t] + a[i][j];
					pre[i][j] = t;
				}
			}
	int ans = -(1<<30), e = 0;
	for (int i = n; i <= m; i++) {
		if (ans < dp[n][i]) {
			ans = dp[n][i];
			e = i;
		}
	}
	cout << ans << '\n';
	out(n, e);
	return 0;
} 
