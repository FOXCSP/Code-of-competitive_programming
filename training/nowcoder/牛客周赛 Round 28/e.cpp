#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define all(T) T.begin(), T.end() 
#define SZ(T) (int(T.size()))
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const ll mod = 1e9 + 7;
ll qmi(ll a, ll b) {
  a %= mod;
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
void solve(int CaseT = 1) {
  ll n, k;
  cin >> n >> k;
  ll k1, k2;
  k1 = k2 = k / 2;
  if (k & 1) k1++;
  ll ans = 0;
  ll base = (((k2 * k1) % mod) * k1) % mod;
  ans = (ans + qmi(k2, n)) % mod;
  ans = (ans + qmi(base, n / 3) * qmi(k2, (n % 3 >= 1)) % mod * qmi(k1, (n % 3 == 2))) % mod;
  ans = (ans + qmi(base, n / 3) * qmi(k1, (n % 3 >= 1)) % mod * qmi(k2, (n % 3 == 2))) % mod;
  ans = (ans + qmi(base, n / 3) * qmi(k1, (n % 3 >= 1)) % mod * qmi(k1, (n % 3 == 2))) % mod;
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
