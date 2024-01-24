#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  long double t, ans = 0, res = 0;
  cin >> n >> t;
  int m = 0;
  for (int i = 0; i <= n; i++) {
    long double x;
    cin >> x;
    x = x * pow(1.0 + t, -m);
    ans += x;
    // cerr << i << " " << ans << '\n';
    m++;
  }

  cout << fixed << setprecision(3) << ans << '\n';

  return 0;
}