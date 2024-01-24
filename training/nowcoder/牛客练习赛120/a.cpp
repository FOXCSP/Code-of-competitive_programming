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

int vx[200001];

void solve() {
	int n;
	cin >> n;
	int mx = 0;
	int mn = 1ll << 60;
	for (int i = 0; i < n - 1; i++) {
		cin >> vx[i];
		mx = max(mx, vx[i]);
		mn = min(mn, vx[i]);
	}
	if (mx != mn) cout << mx << '\n';
	else cout << 1 << '\n';
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
