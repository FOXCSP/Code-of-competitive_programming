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
typedef long double ldb;
typedef double db;
// head
const db EPS = 1e-6;

void solve(int CaseT) {
	int n;
	cin >> n;
	vec<db> a(n + 1, 0), b(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	
	db l = 0, r = 1e9;
	
	auto check = [&](db x) {
		db l = -1e9, r = 1e9;
		for (int i = 1; i <= n; i++) {
			l = max(a[i] - b[i] * x, l);
			r = min(a[i] + b[i] * x, r);
		}
		return l <= r;
	};
	for (int i = 1; i <= 100; i++) {
		db mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(10);	 
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
