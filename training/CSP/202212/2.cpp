#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> p(m + 1, 0), l(m + 1, 0), r(m + 1, 0), t(m + 1, 0);
  map<int, vector<int>> mp;
  for (int i = 1; i <= m; i++) {
    cin >> p[i];
    if (p[i]) mp[p[i]].pb(i);
  }

  for (int i = 1; i <= m; i++) 
    cin >> t[i];
  
  for (int i = 1; i <= m; i++) {
    l[i] = 1;
    if (p[i])
      l[i] = l[p[i]] + t[p[i]];
  }
  
  for (int i = m; i >= 1; i--) {
    r[i] = n - t[i] + 1;
    for (auto x : mp[i]) {
      r[i] = min(r[i], r[x] - t[i]);
    }
  }

  bool f = 1;
  for (int i = 1; i <= m; i++) {
    cout << l[i] << " \n"[i == m];
    if (r[i] < l[i] || l[i] > n || r[i] < 1) f = false;
  }

  for (int i = 1; i <= m && f; i++) {
    cout << r[i] << " \n"[i == m];
  }
      
  return 0;
}