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
  ll n, f, a, b;
  cin >> n >> f >> a >> b;
  vector<ll> vx(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> vx[i];
  for (int i = 1; i <= n; i++) {
    if ((vx[i] - vx[i - 1]) * a > b) f -= b;
    else f -= (vx[i] - vx[i - 1]) * a;
  }
  if (f > 0) cout << "YES\n";
  else cout << "NO\n";
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