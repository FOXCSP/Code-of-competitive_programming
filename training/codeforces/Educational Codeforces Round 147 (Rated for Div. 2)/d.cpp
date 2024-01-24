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
	int n, k;
	cin >> n >> k;
	vec<int> l(n+1), r(n+1);
	for (int i = 1; i <= n; i++)
		cin >> l[i];
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	int sum = 0, cnt = 0, ans = 1 << 30;
	for (int i = 1; i <= n; i++) {
		int len = r[i] - l[i] + 1;
		cnt += (len == 1);
		sum += len;
		if (sum >= k) {
			int t = sum - k;
			int res = r[i] - t + i * 2 - min(t, cnt);
			ans = min(ans, res); 
		}
	}
	if (ans == 1 << 30) ans = -1;
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
