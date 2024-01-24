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
int fa[N][20], dep[N], n, m, v[N], val[N][20];
vector<int> e[N];

void dfs(int u, int f) {
  dep[u] = dep[f] + 1;
  fa[u][0] = f;
  val[u][0] = v[u];
  for (int i = 1; i < 20; i++)
    fa[u][i] = fa[fa[u][i - 1]][i - 1],
    val[u][i] = min(val[u][i - 1], val[fa[u][i - 1]][i - 1]);
  for (auto v : e[u]) {
    if (v == f) continue;
    dfs(v, u);
  }
}

int query(int a, int b) {
  int ans = min(v[a], v[b]);
  if (dep[a] < dep[b])
    swap(a, b);
  for (int i = 19; i >= 0; i--)
    if (dep[fa[a][i]] >= dep[b]) {
      ans = min(ans, val[a][i]);
      a = fa[a][i];
    }
  if (a == b)
    return min(ans, v[a]);
  for (int i = 19; i >= 0; i--)
    if (fa[a][i] != fa[b][i]) {
      ans = min(val[a][i], ans);
      ans = min(val[b][i], ans);
      a = fa[a][i];
      b = fa[b][i];
    }
  ans = min(ans, v[a]);
  ans = min(ans, v[b]);
  return min(ans, v[fa[a][0]]);
}

void solve(int CaseT) {
  cin >> n >> m;
  memset(val, 0x3f, sizeof val);
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].pb(v);
    e[v].pb(u);
  }

  dfs(1, 0);

  for (; m--; ) {
    int u, v;
    cin >> u >> v;
    cout << query(u, v) << '\n';
  }
}

int main() {
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
