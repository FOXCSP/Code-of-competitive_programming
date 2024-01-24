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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int q;
  cin >> q;
  for (int _ = 1; _ <= q; _++) {
  	int n, k;
  	cin >> n >> k;
  	int t = (n - 1) / 2;
  	int mn = 2 + n - 1;
  	int d = k - mn;
  	if (d == 0) {
  		cout << "0\n";
		} else if (d & 1) {
			cout << "-1\n";
		} else {
			int rp = d / 4;
			if ((d / 4) + (d % 4 != 0) > t) {
				cout << "-1\n";
				return 0;
			}
			int ans = d / 4 * 2 + (d % 4 != 0);
			cout << ans << '\n';
		}
	} 
	 
  return 0;
}
