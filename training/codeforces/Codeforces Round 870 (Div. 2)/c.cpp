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
  int n, m;
  cin >> n >> m;

  if (n % m == 0 && m > 1) {
    cout << "NO\n";
    return ;
  }

  if (n < m && n > 1) {
    cout << "NO\n";
    return ;
  }
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      if (m >= i) {
        cout << "NO\n";
        return ;
      }
    }
  }
  cout << "YES\n";
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