#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

const int N = 1000010;
const ll mod1 = 998244353, base1 = 1331;
const ll mod2 = 1000000009, base2 = 2333;
ll n, m, k;
string s;
pair<ll, ll> hs[N], pw[N], base = {base1, base2};

pair<ll, ll> operator * (const pair<ll, ll> &L, const pair<ll, ll> &R) {
  return pair<ll, ll>{(L.fi * R.fi) % mod1, (L.se * R.se) % mod2};
}
pair<ll, ll> operator + (const pair<ll, ll> &L, const pair<ll, ll> &R) {
  return pair<ll, ll>{(L.fi + R.fi) % mod1, (L.se + R.se) % mod2};
}
pair<ll, ll> operator - (const pair<ll, ll> &L, const pair<ll, ll> &R) {
  return pair<ll, ll>{(L.fi - R.fi + mod1) % mod1, (L.se - R.se + mod2) % mod2};
}
pair<ll, ll> get(int l, int r) {
  return (hs[r] - hs[l - 1] * pw[r - l + 1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k >> s;
  
  s = "#" + s;

  pw[0] = {1, 1};
  for (int i = 1; i <= 1000000; i++) pw[i] = (pw[i - 1] * base);
  for (int i = 1; i <= n; i++) {
    hs[i] = (hs[i - 1] * base + pair<ll, ll>{s[i], s[i]});
  }

  map<pair<ll, ll>, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    if (i - m + 1 >= 1) {
      auto z = get(i - m + 1, i);
      mp[z].pb(i);
    }
  }
  
  map<pair<ll, ll>, int> ans;
  for (auto &[x, vx] : mp) {
    int pre = -1e9, res = 0;
    for (auto y : vx) {
      if (y - m + 1 > pre) {
        pre = y;
        res++;
      }
    }
    ans[x] = res;
  }

  int cnt = 0;

  for (auto [x, y] : ans) {
    if (y == k) {
      cnt++;
    }
  }

  cout << cnt << '\n';
  return 0;
} 
