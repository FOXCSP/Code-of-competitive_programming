#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0); cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> vx;
  for (int i = 1; i <= n; i++) {
    int t, c;
    cin >> t >> c;
    vx.pb({t, c});
  }
  
  auto check = [&](int x) -> bool {
    int res = m;
    for (auto p : vx) {
      int t = p.first, c = p.second;
      if (t > x) {
        if (x < k) return false;
        res -= max(0, t - x) * c;
        if (res < 0) return false;
      }
    }
    return true;
  };

  int l = 1, r =1e9;
  
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }

  cout << l << '\n';

  return 0;
}