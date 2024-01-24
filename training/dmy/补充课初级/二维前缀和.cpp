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

const int N = 2010;
int n, m, q;
unsigned int A, B, C;
long long a[N][N], s[N][N];
inline unsigned int rng61() {
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}
int main(){
  scanf("%d%d%d%u%u%u", &n, &m, &q, &A, &B, &C);
  for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
          a[i][j] = rng61();
      }
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
  long long ans = 0;
  for (int i = 1; i <= q; i++) {
      int x1 = rng61() % n + 1, x2 = rng61() % n + 1;
      int y1 = rng61() % m + 1, y2 = rng61() % m + 1;
      if (x1 > x2) swap(x1, x2);
      if (y1 > y2) swap(y1, y2);
      // 执行查询操作
      ans ^= (a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1]);
  }
  cout << ans << '\n';
  return 0;
}