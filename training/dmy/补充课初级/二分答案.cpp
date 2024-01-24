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
	ll n, k;
	cin >> n >> k;
	vec<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i]; 
		
	auto calc = [&](ll x) {
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			res += max(0ll, x - a[i]);
		}
		return res;
	};
		
	ll l = 0, r = 1e14;
	while (l < r) {
		ll mid = (l + r + 1) / 2;
		if (calc(mid) <= k) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
