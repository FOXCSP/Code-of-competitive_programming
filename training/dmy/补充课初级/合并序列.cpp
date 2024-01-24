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
	int n, m;
	cin >> n;
	vec<int> k(n + 1, 0), b(n + 1, 0);
	for (int i = 1; i <= n; i++) 
		cin >> k[i] >> b[i];
	cin >> m;
	
	int l = 0, r = 1e9;
	
	auto calc = [&](int x){
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			if (x >= b[i]) 
				res += (x - b[i]) / k[i] + 1;
		}
		return res;
	};
	
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (calc(mid) <= m) 
			l = mid;
		else 
			r = mid - 1;
	}
	auto ans = [&](int res) {
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			if (res >= b[i]) {
				int x = (res - b[i]) / k[i] + 1;
				sum += 1ll * x * b[i] + 1ll * k[i] * (x - 1) * x / 2;
			}
		}
		return sum;
	};
	cout << ans(l) + (1LL * (m - calc(l)) * (l + 1)) << '\n';
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
