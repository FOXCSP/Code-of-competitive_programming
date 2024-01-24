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
int a[N], fa[N][20], n, q;
// fa[i][j] 表示 i 切 (1 << j) 刀最远切到哪

int cnt, prime[N], v[N];
bool vis[N];
vector<int> c[N];
int query(int l, int r) {
  int res = 0;
  for (int i = 19; i >= 0; i--) {
    if (fa[l][i] <= r) {
      res += (1 << i);
      l = fa[l][i];
    }
  }
  return res + 1;
}

void solve(int CaseT) {
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  memset(fa, 0x3f, sizeof fa);
  memset(v,  0x3f, sizeof v);
  fa[n + 1][0] = n + 1;
  for (int i = n; i; i--) {
    fa[i][0] = fa[i + 1][0];
    for (auto j : c[a[i]]) {
      fa[i][0] = min(fa[i][0], v[j]);
      v[j] = i;
    }
  }

  for (int i = 1; i <= 19; i++)
    for (int j = 1; j <= n; j++)
      if (fa[j][i - 1] <= n)
        fa[j][i] = fa[fa[j][i - 1]][i - 1];
      else
        fa[j][i] = n + 1;


  for (; q--; ) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;

  for (int i = 2; i <= 100000; i++) {
    if (!vis[i]) prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= 100000; j++) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
    }
  }

  for (int i = 1; i <= cnt; i++)
    for (int j = prime[i]; j <= 100000; j += prime[i])
      c[j].pb(prime[i]);

//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
