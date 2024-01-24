#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define fi first
#define se second
#define P(T) pair<T, T>
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define all(T) T.begin(), T.end()
#define pb push_back 
using namespace std;
typedef long long ll;
typedef long double ldb;
//  head

const ll mod = 998244353;

int dp[40][20][20][20][3];

void solve(int CaseT = 1) {
	int x, n, m, k;
	cin >> x >> n >> m >> k;
	memset(dp, 0, sizeof dp);
	
	// xue
	// ·¨Á¦
	// ±ùÇ¹Êé
	// º®±ù¼ý 
	
/*
1
6 3 9 2



1
30 10 10 10
*/
	dp[x][n][k][m - k][0] = 1;
	for (int i = x; i >= 0; i--) {
		for (int j = n; j >= 0; j--) {
				for (int p = k; p >= 0; p--) {
					for (int q = m - k; q >= 0; q--) {
					if (j && p) dp[i][j - 1][p - 1][q][1] |= dp[i][j][p][q][0];
					if (j >= 2 && q) dp[max(0, i - 3)][j - 2][p][q - 1][1] |= dp[i][j][p][q][0];
					if (j >= 2 && q) dp[max(0, i - 3)][j - 2][p][q - 1][1] |= dp[i][j][p][q][1];
					if (j && p) dp[max(0, i - 4)][j - 1][p - 1][q][1] |= dp[i][j][p][q][1];
					
				}
			}
		}
	}
	
	bool ans = 0;
	for (int j = 0; j <= n; j++) {
		for (int p = 0; p <= k; p++) {
			for (int q = 0; q <= m - k; q++) {
				ans |= dp[0][j][p][q][0];
				ans |= dp[0][j][p][q][1];
			}
		}
	}
	cout << (ans? "Yes":"No") <<'\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_=1;
	cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	
	return 0;
}
