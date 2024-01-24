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

void solve(int CaseT) {
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = n / i;
		ans += (1ll * x * (x + 1) / 2) * i;
		if (((n / i) * i - n + i - 1))
			ans -= (n / i) * ((n / i) * i - n + i - 1);
	}
	cout << ans << '\n';
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _=1;
  cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
