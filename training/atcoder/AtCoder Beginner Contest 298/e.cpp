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
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const int N = 110;
const ll mod = 998244353; 
int n, m;
ll dp[N][N][2];

ll qmi(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

void solve(int CaseT = 1) {
	cin >> n;
	ll a, b;
	ll p, q;
	cin >> a >> b >> p >> q;
	ll inp = qmi(p, mod - 2);
	ll inq = qmi(q, mod - 2);
	dp[a][b][1] = 1;
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= p; k++)
				dp[min(n, k + i)][j][1] = (dp[min(n, k + i)][j][1] + dp[i][j][0] * inp) % mod;
			for (int k = 1; k <= q; k++)
				dp[i][min(n, k + j)][0] = (dp[i][min(n, k + j)][0] + dp[i][j][1] * inq) % mod;
		}
	}
	
	
	ll ans = 0;
	ans = (ans + dp[n][n][1]) % mod;
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
