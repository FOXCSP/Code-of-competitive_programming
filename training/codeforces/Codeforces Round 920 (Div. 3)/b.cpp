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
  string a, b;
  int n;
  cin >> n >> a >> b;
  int x = 0, ans = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) continue;
    if (a[i] == '1') {
      if (y) y--, ans++;
      else x++;
    }
    else {
      if (x) x--, ans++;
      else y++;
    }
  }
  while (x && y) {
    x--, y--;
    ans++;
  }
  while (x) {
    x--;
    ans++;
  }
  while (y) {
    y--;
    ans++;
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