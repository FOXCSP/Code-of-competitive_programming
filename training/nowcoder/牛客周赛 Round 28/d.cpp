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

void solve(int CaseT = 1) {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1, 0);
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    cin >> a[i], a[i] += a[i - 1];
  a[n + 1] = 1e18;
  for (int i = 1; i <= n; i++) {
    int l = i, r = n + 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (a[mid] - a[i - 1] >= k) r = mid;
      else l = mid + 1;
    }
    ans += n - r + 1;
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
