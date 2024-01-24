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

int dp[N][3], n;
int a[N], b[N], c[N];

void solve(int CaseT = 1) {
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
	
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max({dp[i][0], dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]});
		dp[i][1] = max({dp[i][1], dp[i - 1][0] + b[i], dp[i - 1][2] + b[i]});
		dp[i][2] = max({dp[i][2], dp[i - 1][0] + c[i], dp[i - 1][1] + c[i]});
	}
	
	cout << max({dp[n][0], dp[n][1], dp[n][2]}) <<'\n';
	
	
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
