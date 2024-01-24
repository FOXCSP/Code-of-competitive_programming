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
	vec<int> a(n + 1, 0), b(n + 1, 0);
	int l = 1, r = n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	
	while (l <= n && a[l] == b[l]) l++;
	while (r >= 1 && a[r] == b[r]) r--;
	if (l > r) {
		vec<int> f(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (i > 1 && a[i] >= a[i - 1]) f[i] = f[i - 1] + 1;
			else f[i] = 1;
		}
		r = max_element(f.begin(), f.end()) - f.begin();
		l = r;
		while (f[l] != 1) l--;
		cout << l << " " << r << '\n'; 
	}	else {
	
		int mx = -(1 << 30), mn = (1 << 30);	
		for (int i = l; i <= r; i++) {
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
		
		while (l > 1 && a[l - 1] <= mn) l--, mn = min(mn, a[l]);
		while (r < n && a[r + 1] >= mx) r++, mx = max(mx, a[r]);
		cout << l << " " << r << '\n'; 
	}
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
