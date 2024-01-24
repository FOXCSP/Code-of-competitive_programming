#include <bits/stdc++.h>
#define int long long 
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
#define P(T) pair<T, T>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
// head

const int N = 110;
const ll mod = 998244353;

ll qmi(ll a, ll b) {
	ll res=1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

ll dp[64][64][64];
ll n, m; 
void solve(int CaseT) {
	cin >> n;
	ll a = 0, b = 0, c = 0;
	ll x = n;
	while (x % 2 == 0) {
		x /= 2;
		a++;
	}
	while (x % 3 == 0) {
		x /= 3;
		b++;
	}
	while (x % 5 == 0) {
		x /= 5;
		c++;
	}
	if (x > 1) {
		cout << 0 << '\n';
		return ;
	}
	dp[0][0][0] = 1;
	ll inv = qmi(5, mod-2);
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				ll &x = dp[i][j][k];
				if (i) 
					x = (x + dp[i - 1][j][k] * inv % mod + mod) % mod;
				if (j) 
					x = (x + dp[i][j - 1][k] * inv % mod + mod) %mod;
				if (i - 2 >= 0) 
					x = (x + dp[i - 2][j][k] * inv % mod + mod) % mod;
				if (k) 
					x = (x + dp[i][j][k - 1] * inv % mod + mod) % mod;
				if (i && j) 
					x = (x + dp[i - 1][j - 1][k] * inv % mod + mod) % mod;
			}
		}
	}
	cout << (dp[a][b][c] % mod + mod) % mod << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
	int _;
  _=1;
//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}

