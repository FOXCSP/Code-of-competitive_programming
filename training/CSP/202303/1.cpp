#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0); cout.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 = max(0, x1), x2 = max(0, x2), y1 = max(0, y1), y2 = max(0, y2);
    x1 = min(a, x1), x2 = min(a, x2), y1 = min(b, y1), y2 = min(b, y2);
    ans += max(0, (x2 - x1) * (y2 - y1));
  }
  cout << ans << '\n';
  return 0;
}