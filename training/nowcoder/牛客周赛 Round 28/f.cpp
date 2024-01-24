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

ll s[100001], ans, n, k;
void solve(int CaseT = 1) {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) {
    s[i] += s[i - 1];
  }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      if (s[j] - s[i - 1] >= k) ans++;
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
