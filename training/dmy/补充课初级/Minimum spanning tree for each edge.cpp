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
const int N = 200010;
int fa[N][20], dep[N], n, m, v[N], val[N][20], bel[N];
vector<pair<int, int>> e[N];

void dfs(int u, int f) {
  dep[u] = dep[f] + 1;
  for (auto [v, w] : e[u]) {
    if (v == f) continue;
    val[v][0] = w;
    fa[v][0] = u;
    dfs(v, u);
  }
}

int query(int a, int b) {
  int ans = - (1 << 30);
  if (dep[a] < dep[b])
    swap(a, b);
  for (int i = 19; i >= 0; i--)
    if (dep[fa[a][i]] >= dep[b]) {
      ans = max(ans, val[a][i]);
      a = fa[a][i];
    }
  
  if (a == b) {
    return ans;
  }
  for (int i = 19; i >= 0; i--)
    if (fa[a][i] != fa[b][i]) {
      ans = max(val[a][i], ans);
      ans = max(val[b][i], ans);
      a = fa[a][i];
      b = fa[b][i];
    }
  ans = max(val[a][0], ans);
  ans = max(val[b][0], ans);
  return ans;
}

vector<array<int, 3>> edge, eg;

int p[N];
int find(int x) {
  return x == p[x] ? x : p[x] = find(p[x]);
}

ll kruscal() {
  sort(all(edge));
  ll res = 0;
  for (int i = 1; i <= n; i++)
    p[i] = i;
  for (auto x : edge) {
    int px = find(x[1]);
    int py = find(x[2]);
    if (px != py) {
      p[px] = py;
      eg.pb(x);
      res += x[0];
    }
  }
  return res;
}

void solve(int CaseT) {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.pb({w, u, v});
  }
  auto bp = edge;
  auto res = kruscal();
  for (auto x : eg) {
    e[x[1]].pb({x[2], x[0]});
    e[x[2]].pb({x[1], x[0]});
  }


  dfs(1, 0);
  
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= n; j++)
      fa[j][i] = fa[fa[j][i - 1]][i - 1],
      val[j][i] = max(val[j][i - 1], val[fa[j][i - 1]][i - 1]);
  
  for (auto x : bp) {
    ll u = x[1], v = x[2], w = x[0];
    ll y = query(u, v);
    cout << res - y + w << '\n';
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
