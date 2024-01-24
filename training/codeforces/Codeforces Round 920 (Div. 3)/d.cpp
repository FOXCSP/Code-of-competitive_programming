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

void solve(int CaseT) {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n + 1, 0), b(m + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(all(a));
  sort(all(b));
  ll l = 1, r = m, L = 1, R = n, ans = 0;
  vector<ll> c(n + 1, 0);
  while (L <= R) {
    int x, fx, y, fy;
    if (abs(a[L] - b[r]) >= abs(a[L] - b[l])) x = b[r], fx = 1;
    else x = b[l], fx = 0;
    if (abs(a[R] - b[r]) >= abs(a[R] - b[l])) y = b[r], fy = 1;
    else y = b[l], fy = 0;
    if (abs(a[L] - x) > abs(a[R] - y)) {
      c[L] = x;
      if (fx) r--;
      else l++;
      L++;
    } else {
      c[R] = y;
      if (fy) r--;
      else l++;
      R--;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += abs(c[i] - a[i]);
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _=1;
  cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}