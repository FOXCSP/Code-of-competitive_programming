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
ll qmi(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

/*

5
1 1
4 5
1 4
19 19
8 10

1
19 19
*/

ll C[2100][2100]; 

void solve(int CaseT = 1) {
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	C[1][0] = 1, C[1][1] = 1;
	for (int i = 2; i < 2050; i++) {
		for (int j = 0; j < 2050; j++) {
			if (!j) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	
	for (int x = 0; x <= n ; x++) {
		for (int p = 1; p <= n; p++) {
			if (2LL * p == 3LL * x - n - k) {
				if (n - x < p - 1) continue;
				if (n - x + 1 < 0 || x - p - 1 < 0) continue;
				ans = (ans + C[n - x + 1][p] * C[x - p - 1][p - 1]) % mod;
				cout << x << " " << p << " xxx\n";
				cout << n - x + 1 << " " << p << " " << x - p - 1 << " " << p - 1 << '\n';
			}
		}
	}
	
	
	
	cout << ans << '\n';
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
