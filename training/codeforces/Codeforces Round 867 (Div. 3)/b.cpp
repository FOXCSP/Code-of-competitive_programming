#include <bits/stdc++.h>
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
typedef long double lbd;
// head

void solve(int CaseT) {
	int n;
	cin >> n;
	vec<int> a, b;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x < 0) b.pb(x);
		else a.pb(-x); 
	}
	sort(all(a));
	sort(all(b));
	ll ans = -(1ll << 62);
	if (SZ(a) > 1) {
		int t = SZ(a);
		ans = max(ans, 1ll * a[0] * a[1]);
	}
	if (SZ(b) > 1) {
		int t = SZ(b);
		ans = max(ans, 1ll * b[0] * b[1]);
	}
	if (SZ(b) && SZ(a)) {
		ans = max(ans, 1LL * b.back() * (-a.back()));
	}
	cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
