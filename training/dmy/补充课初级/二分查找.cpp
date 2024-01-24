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
	cin >> n >> m;
	vec<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (; m--; ) {
		int x;
		cin >> x;
		int l = lower_bound(a.begin(), a.end(), x) - a.begin();
		int r = upper_bound(a.begin(), a.end(), x) - a.begin();
		int r1, r2 = r - l, r3 = n - r + 1;
		if (l > n || a[l] > x)
			r2 = 0;
		if (r > n)
			r3 = 0;
		cout << n - r2 - r3 << " " << r2 << " " << r3 << '\n'; 
	}
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
