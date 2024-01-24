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
	
	int a, k, q;
	cin >> a >> k >> q;
	
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		if (k & 1) {
			if ((r - l + 1) & 1) {
				bool f = a & 1;
				if (l % 2 == 0) f ^= 1;
				cout << (f ? 1 : -1) << '\n'; 
			} else {
				cout << "0\n";
			}
		} else {
			cout << ((a & 1) ? 1 : -1) << '\n';
		}
	}
  return 0;
}
