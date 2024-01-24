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
mt19937_64 rnd(time(0));
typedef long long ll;
typedef long double ldb;
typedef double db;
// head

const int N = 100010;
int a[N], b[N], c[N], n, m;
void solve(int CaseT) {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], b[i] = a[i] + i, c[i] = a[i] - i;
  for (int i = 1; i <= n; i++)
    b[i] = max(b[i - 1], b[i]);
  for (int i = n - 1; i >= 1; i--)
    c[i] = max(c[i + 1], c[i]);

  int ans = -(1<<30);
  for (int i = 2; i < n; i++)
    ans = max(ans, a[i] + b[i - 1] + c[i + 1]);
  cout << ans << '\n';
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