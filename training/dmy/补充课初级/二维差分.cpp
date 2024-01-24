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

const int N = 8010;
int n, m, q;
long long a[N][N], s[N][N];
int main(){
  cin >> n >> m >> q;

  vector<int> vx, vy;
  vector<array<int, 5>> evt;
  for (int i = 1; i <= q; i++) {
    int x1, y1, x2, y2, d;
    cin >> x1 >> y1 >> x2 >> y2 >> d;
    evt.pb({x1, y1, x2, y2, d});
    vx.pb(x1);
    vx.pb(x2);
    vy.pb(y1);
    vy.pb(y2);
    vx.pb(x2 + 1);
    vy.pb(y2 + 1);
  }

  sort(all(vx));
  sort(all(vy));
  vx.erase(unique(all(vx)), vx.end());
  vy.erase(unique(all(vy)), vy.end());

  for (int i = 0; i < SZ(evt); i++) {
    int x1, y1, x2, y2, d;
    x1 = lower_bound(all(vx), evt[i][0]) - vx.begin() + 1;
    y1 = lower_bound(all(vy), evt[i][1]) - vy.begin() + 1;
    x2 = lower_bound(all(vx), evt[i][2]) - vx.begin() + 1;
    y2 = lower_bound(all(vy), evt[i][3]) - vy.begin() + 1;
    d  = evt[i][4];
    a[x1][y1] += d;
    a[x2 + 1][y1] -= d;
    a[x1][y2 + 1] -= d;
    a[x2 + 1][y2 + 1] += d;
  }
  for (int i = 1; i <= SZ(vx); i++)
    for (int j = 1; j <= SZ(vy); j++)
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];

  ll ans = 0;
  for (int i = 1; i <= SZ(vx); i++)
    for (int j = 1; j <= SZ(vy); j++) {
      ll num = 1ll * (vx[i] - vx[i - 1]) * (vy[j] - vy[j - 1]);
      if (num & 1)
        ans ^= a[i][j];
    }
  cout << ans << '\n';
  return 0;
}