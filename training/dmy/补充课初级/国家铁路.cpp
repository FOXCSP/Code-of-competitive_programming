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
const int N = 1010;
int n, m, c;
ll a[N][N], w[N][N];
ll sol() {
  // memset(w, 0x3f, sizeof w);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      w[i][j] = 1e18;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      w[i][j] = a[i][j] - 1ll * (i + j) * c,
      w[i][j] = min({w[i][j], w[i - 1][j], w[i][j - 1]});
  ll ans = 1e18;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      ans = min(ans, 1ll * a[i][j] + 1ll * c * (i + j) + min(w[i - 1][j], w[i][j - 1]));
  return ans;
}

void solve(int CaseT) {
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j];
  auto ans = sol();
  for (int i = 1; i <= n; i++)
    reverse(a[i] + 1, a[i] + m + 1);
  ans = min(ans, sol());
  cout << ans << '\n';
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
