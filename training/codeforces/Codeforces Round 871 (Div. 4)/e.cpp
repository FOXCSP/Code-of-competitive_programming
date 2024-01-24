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
const int N = 1010;
int g[N][N], col[N][N], cl;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

int bfs(int x, int y) {
  queue<P(int)> heap;
  heap.push({x, y});
  int res = 0;
  col[x][y] = cl;
  while (!heap.empty()) {
    auto [a, b] = heap.front(); heap.pop();
    res += g[a][b];
    for (int i = 0; i < 4; i++) {
      int na = a + D[i][0];
      int nb = b + D[i][1];
      if (na < 1 || na > n || nb < 1 || nb > m) continue;
      if (g[na][nb] == 0 || col[na][nb]) continue;
      col[na][nb] = cl;
      heap.push({na, nb});
    }
  }
  return res;
};

void solve(int CaseT) {
  cin >> n >> m;
  cl = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> g[i][j];
  
  int ans = 0;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) 
      if (!col[i][j] && g[i][j]) 
        cl++, ans = max(ans, bfs(i, j));
  cout << ans << '\n';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      col[i][j] = 0;
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