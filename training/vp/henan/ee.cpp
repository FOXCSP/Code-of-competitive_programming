#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
// head

int dp[2][501][1001];
char g[501][501];
int n, m, x;
string s;
void solve(int CaseT) {
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			g[i][j + 1] = s[j]; 
		}
	}
	
	int flg = 1;
//	dp[1][1][x] = (g[1][1] == '1');
//	if (g[1][1] == '?') dp[1][1][x - 1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = x; k >= 0; k--) {
//				if (g[i][j - 1] == '0' && j > 1)
//					dp[flg][j][k] = max(dp[flg][j][k], dp[flg][j - 1][k]);
//				if (g[i][j - 1] == '1' && j > 1)
//					dp[flg][j][k] = max(dp[flg][j][k], dp[flg][j - 1][k] + 1);
//				if (g[i][j - 1] == '?' && j > 1)
//					dp[flg][j][k] = max(dp[flg][j][k], dp[flg][j - 1][k]);
//				if (g[i][j - 1] == '?' && j > 1 && k)
//					dp[flg][j][k - 1] = max(dp[flg][j][k - 1], dp[flg][j - 1][k] + 1);
//				
//				if (g[i - 1][j] == '0')
//					dp[flg][j][k] = max(dp[flg][j][k], dp[flg ^ 1][j][k]);
//				if (g[i - 1][j] == '1')
//					dp[flg][j][k] = max(dp[flg][j][k], dp[flg ^ 1][j][k] + 1);
//				if (g[i - 1][j] == '?')
//					dp[flg][j][k] = max(dp[flg][j][k], dp[flg ^ 1][j][k]);
//				if (g[i - 1][j] == '?' && k)
//					dp[flg][j][k - 1] = max(dp[flg][j][k - 1], dp[flg ^ 1][j][k] + 1);
//				
				
				if (g[i][j] == '0') {
					dp[flg][j][k] = max(dp[flg][j][k], max(dp[flg ^ 1][j][k], dp[flg][j - 1][k]));
				} else if (g[i][j] == '1') {
					dp[flg][j][k] = max(dp[flg][j][k], max(dp[flg ^ 1][j][k], dp[flg][j - 1][k]) + 1);
				} else {
					dp[flg][j][k] = max(dp[flg][j][k], max(dp[flg ^ 1][j][k], dp[flg][j - 1][k]));
					if (k) dp[flg][j][k - 1] = max(dp[flg][j][k - 1], max(dp[flg ^ 1][j][k], dp[flg][j - 1][k]) + 1);
				}
				
			}
		}
		flg ^= 1;
	}
	
	int res = 0;
	for (int i = 0; i <= x; i++) {
		res = max(res, dp[flg ^ 1][m][i]);
	}
	
	cout << res << '\n';
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= x; k++)
				dp[i][j][k] = 0;
}	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}

/*
1
3 3 100
000
000
00?

1
3 3 100
???
???
???

1
3 3 100
???
???
??0

  
 */
