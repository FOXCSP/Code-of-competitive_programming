#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
#define P(T) pair<T, T>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
// head

bool on(int x, int now) {
  if (x - 1 == now * (now - 1) / 2 || x == now * (now + 1) / 2) {
    return true;
  }
  return false;
}

void solve(int CaseT) {
  int n;
  cin >> n;
  int x = floor(sqrt(n));
  if (x * (x + 1) / 2 > n) x--;
  ll ans = 0;
  int l,r,now = x + (n % ((x*(x+1)/2)) != 0);
  cout << "now " << now << '\n';
  l=n,r=n;
  int id = 10;
  while (id > 0) {
    id --;
    ll res = 0;
    cout << l << " " << r << '\n';
    for (int i = l; i <= r; i++)
      res += i * i;
    ans += res;
    if (on(l, now) || on(r, now)) {
      cout << " ck \n";
      while (id > 0) {
        id--;
        cout << l << " " << r << " " << now << '\n';
        r -= (r - l + 1), l -= (now - 1);
        res = 0;
        cout << " add: " << l << " " << r << '\n';
        for (int i = l; i <= r; i++)
          res += i * i;
        ans += res;
        if (l == r) {
          break;
        }
        now--;
      }
    }
    l -= now, r -= (now - 1);
    now--;
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