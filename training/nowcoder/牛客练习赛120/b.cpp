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
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
// head

void solve() {
	int r=0, m;
	for (int i = 0; i < 3; i++) {
		int x;
		cin >> x;
		r = __gcd(r, x);
	}
	cin >> m;
	if (m % r) cout << "NO\n";
	else cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int _ = 1;
  cin >> _;

  for (int i = 0; i < _; i++) solve();
  
  return 0;
}
