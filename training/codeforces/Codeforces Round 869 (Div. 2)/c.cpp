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

const int N = 110;

void solve(int CaseT) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1, 0);
  for (int i = 1;i <= n; i++)
    cin >> a[i];
  vector<pair<int, int>> vx;
  vx.pb({a[1], 1});
  for (int i = 2; i <= n; i++) {
    if (vx.back().fi >= a[i])
      vx.back().se++, vx.back().fi = a[i];
    else 
      vx.pb({a[i], 1});
  }
  int m = SZ(vx);

  pair<ll, ll> f[m + 1];
  f[0] = {0, 0};
  for (int i = 1; i <= m; i++) {
    f[i].fi = vx[i - 1].se;
    f[i].se = min(2, vx[i - 1].se);
  }
  
  for (int i = 1; i <= m; i++)
    f[i].fi += f[i - 1].fi,
    f[i].se += f[i - 1].se;



  for (int i = 1; i <= k; i++) {
    int l, r;
    cin >> l >> r;
    int p1 = lower_bound(f + 1, f + m + 1, pair<ll, ll>{l, 0}) - f;
    int p2 = lower_bound(f + 1, f + m + 1, pair<ll, ll>{r, 0}) - f;
    //
    ll ans = f[p2].se - f[p1 - 1].se;
    ans -= (f[p1].se - f[p1 - 1].se);
    ans += min(2ll, min(1ll * r, f[p1].fi) - l + 1);
    ans -= (f[p2].se - f[p2 - 1].se);
    ans += min(2ll, r - f[p2-1].fi);
    cout << max(1LL, ans) << '\n';
  }
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