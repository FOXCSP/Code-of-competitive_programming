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
	int n, t;
	cin >> n >> t;
	vec<int> a(n + 1, 0), b(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += i - 1;
	} 
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	int ans = 0, p;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= t) {
			if (ans < b[i]) {
				ans = b[i];
				p = i;
			}
		}
	}
	if (ans) cout << p << '\n';
	else cout << -1 << '\n';
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
