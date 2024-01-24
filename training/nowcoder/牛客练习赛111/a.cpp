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
  int a;
  cin >> a;
  for (int i = 1; i <= 8; i++) {
    if (a % 10 != 0) {
      int ans = (10-a%10);
      for (int j = 1; j <= i; j++)
        ans = ans * 10;
      cout << ans << '\n';
      return ;
    }
  }
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
