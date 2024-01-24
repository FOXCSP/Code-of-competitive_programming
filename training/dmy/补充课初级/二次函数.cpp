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
typedef double db;
// head
void solve(int CaseT) {
  db a, b, c;
  cin >> a >> b >> c;
  db l = -500, r = 500;
  auto f = [&](db x) {
    return 1.0 * a * x * x + b * x + c;
  };
  for (int i = 1; i <= 100; i++) {
    db m1 = (r - l) / 3 + l, m2 = (r - l) / 3 * 2 + l;
    if (f(m1) >= f(m2))
      l = m1;
    else
      r = m2;
  }
  cout << fixed << setprecision(10) << f(l) << '\n';
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
