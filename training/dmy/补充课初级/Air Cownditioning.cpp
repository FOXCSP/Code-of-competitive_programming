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
  int n;
  cin >> n;
  vec<int> a(n + 2, 0), b(n + 2, 0);
  int res = 0;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i], a[i] -= b[i];
  for (int i = 1; i <= n + 1; i++)
    if (a[i] > a[i - 1]) 
      res += (a[i] - a[i - 1]);
  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;

  // cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
