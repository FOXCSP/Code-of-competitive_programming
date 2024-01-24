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

const int N = 100010, inf = 1 << 30;
int dp[N], n, a[N], k;

void solve(int CaseT = 1) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++)
		dp[i] = inf;
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i + j <= n) dp[i + j] = min(dp[i + j], dp[i] + abs(a[i + j] - a[i]));
		}
	}
	cout << dp[n] << '\n';
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
