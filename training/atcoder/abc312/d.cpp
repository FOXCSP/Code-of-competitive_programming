#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 3010;
const ll mod = 998244353;

int dp[N][N];
int n;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	n = s.size(); s = "#" + s;

	dp[0][0] = 1;


	for (int i = 1; i <= n; i++) {
		if (s[i] == ')') {
			for (int j = 1; j <= i; j++)
				dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
		}

		if (s[i] == '(') {
			for (int j = 0; j < i; j++)
				dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
		}

		if (s[i] == '?') {
			for (int j = 1; j <= i; j++)
				dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
			for (int j = 0; j < i; j++)
				dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
		}
	}
	cout << dp[n][0] << '\n';
	return 0;
}
