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

int ct[1000010];
void solve(int CaseT) {
	int n;
	cin >> n;
	vec<ll> a(n + 1, 0);
	set<int> S;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ct[a[i]]++;
		S.insert(a[i]);
	}
	ll ans = 0;
	for (auto x : S) {
		for (ll j = 1; x * j * j <= 1e6; j++) {
			int m = ct[x];
			int p = ct[x * j];
			int q = ct[x * j * j];
			if (j == 1)
				ans += (1ll * m * (m - 1) * (m - 2));
			else  
				ans += (1ll * m * p * q);
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++)
		ct[a[i]]--;
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
