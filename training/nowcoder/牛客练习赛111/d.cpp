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
ll x, y;
void exgcd(ll a, ll b) {
    if (!b) {
        x = 1, y = 0;
        return ;
    }
    exgcd(b, a % b);
    ll t = y;
    y = x - a/b * y;
    x = t;
}

void solve(int CaseT) {
  int a, b, n, l, r;
  cin >> a >> b >> n >> l >> r;
  x = y = 0;
  exgcd(a, b);
  int d = __gcd(a, b);
  x = x * (n / d);
  y = y * (n / d);
  int L =  (l - x) / (b / d), R = (r - x) / (b / d);
  // cout << x << " " << y << '\n';
  // cout << L << " " << R << '\n';
  while (L < R) {
    int M = (L + R + 1) / 2;
    if ((y - a / d * M) >= 0) {
      cout << "YES\n";
      return ;
    }
    else R = M - 1; 
  }
  cout << "NO\n";
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
