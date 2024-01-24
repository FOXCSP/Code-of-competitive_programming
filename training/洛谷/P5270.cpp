#include <bits/stdc++.h>
#define int long long
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
typedef unsigned long long ull;
typedef long double ldb;
typedef double db;
mt19937_64 rnd(time(0));
// head
const int N = 400010;
const int inf = 1e18;
const ull M = (1LL << 50) - 1;
ull pw1[N], pw2[N];
pair<ull, ull> hs1, hs2;
int n, t, q, m, p;
int s[N], r[N];
vec<int> a[N];
int ss[N], tt;
int ans[N];

vec<pair<ull, ull>> hs_a[N];

pair<ull, ull> operator + (pair<ull, ull> a, pair<ull, ull> b) {
  return (pair<ull, ull>){
    (a.fi + b.fi), (a.se + b.se) };
}

pair<ull, ull> operator - (pair<ull, ull> a, pair<ull, ull> b) {
  return (pair<ull, ull>){
    (a.fi - b.fi),(a.se - b.se)};
}

void print(pair<ull, ull> tmp) {
  cout << tmp.fi << " " << tmp.se << '\n';
}

void solve(int CaseT) {
  for (int i = 0; i <= 100000; i++) {
    pw1[i] = rnd() ^ M;
    pw2[i] = rnd() ^ M;
  }

  cin >> n >> t >> q;
  for (int i = 1; i <= t; i++) {
    cin >> s[i];
    hs1 = hs1 + pair<ull, ull>(pw1[s[i]], pw2[s[i]]);
  }

  for (int i = 1; i <= n; i++) {
    int l;
    cin >> l;
    pair<ull, ull> pre(0, 0);
    for (int j = 1; j <= l; j++) {
      int x;
      cin >> x;
      a[i].pb(x);
      hs_a[i].pb(pre + pair<ull, ull> (pw1[x], pw2[x]));
      pre = pre + pair<ull, ull> (pw1[x], pw2[x]);
    }
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> r[i];
  }

  int now = 0;
  int step = 1; // 当前是第几步

  for (int i = 1; i <= m; i++)
    ans[i] = inf;

  queue<int> que;
  while (1) {
    bool f = (now >= t);
    for (int i = 1; i <= m; i++, step++) {
      int id = r[i];
      auto v = a[id];
      now += SZ(v);
      que.push(id);
      hs2 = hs2 + hs_a[id].back();
      while (now - SZ(a[que.front()]) > t) {
        now -= SZ(a[que.front()]);
        hs2 = hs2 - hs_a[que.front()].back();
        que.pop();
      }
      int fr = que.front();
      if ((now == t && hs1 == hs2) || (now > t && hs1 == hs2 - hs_a[fr][now - t - 1])) {
        ans[i] = min(ans[i], step);
      }
    }
    if (f) break;
  }

  int res=0;
  for (int i = 1; i <= m; i++)
    if (ans[i] != inf && ans[i] <= q)
      res += (q - ans[i]) / m + 1;
  cout << res << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}

