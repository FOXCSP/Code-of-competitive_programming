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
int n, m;
vec<int> e[210];

bool check(int x) {
  map<int, int> ok;
  int p = 0;
  for (auto v : e[x]) {
    if (v == x) continue;
    ok[SZ(e[v])]++;
    p += SZ(e[v]) - 1;
  }
  if (SZ(ok) != 1 || p + SZ(e[x]) + 1 != n) return false;
  return true;
}

void solve(int CaseT) {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    e[u].pb(v);
    e[v].pb(u);
  }
  bool ok = 1;
  for (int i = 1; i <= n; i++) {
    if (check(i) && ok) {
      int a = SZ(e[i]);
      int b = SZ(e[e[i][0]]) - 1;
      if (a && b) {
        cout << a << " " << b << '\n';
        ok = false;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    e[i].clear();
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