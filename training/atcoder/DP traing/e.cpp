#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const int N = 110, inf = 1 << 30;

int dp[110][100010][2], n, m, v[N], w[N];
int sum;
void solve(int CaseT = 1) {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i], sum += w[i];
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= sum; j++)
			for (int k = 0; k < 2; k++) 
				dp[i][j][k] = inf;
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j][0]);
			if (dp[i - 1][j][0] + v[i] <= m)
				dp[i][j + w[i]][1] = min(dp[i][j + w[i]][1], dp[i - 1][j][0] + v[i]);
			if (dp[i - 1][j][1] + v[i] <= m)
				dp[i][j + w[i]][1] = min(dp[i][j + w[i]][1], dp[i - 1][j][1] + v[i]);
		}
	}
	
	int ans = 0;
//	cout << dp[n][sum][0] << '\n';
	for (int i = sum; i >= 0; i--) 
		if (dp[n][i][0] != inf || dp[n][i][1] != inf) {
			ans = i;
			break;
		}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
//	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
} 
