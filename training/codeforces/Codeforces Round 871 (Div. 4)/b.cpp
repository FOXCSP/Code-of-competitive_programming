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
  vec<int> f(n+1, 0);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (!x) f[i] = f[i - 1] + 1;
    else f[i] = 0;
  }
  cout << *max_element(f.begin(), f.end()) << '\n';
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