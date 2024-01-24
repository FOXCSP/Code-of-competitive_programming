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
const int N = 100010;
int a[N];
void solve(int CaseT) {
  int n;
  cin >> n;
  vec<int> vx;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vx.pb(a[i]);
  }
  sort(all(vx));
  vx.erase(unique(all(vx)), vx.end());
  for (int i = 1; i <= n; i++) {
    int p = lower_bound(all(vx), a[i]) - vx.begin();
    cout << p + 1 << " ";
  }
  cout << '\n';
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
