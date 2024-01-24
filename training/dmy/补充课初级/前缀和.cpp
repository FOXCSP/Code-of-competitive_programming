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
ll a[N], b[N];
void solve(int CaseT) {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    cin >> a[i];
  
  for (; m--; ) {
    int l ,r;
    cin >> l >> r;
    b[l]+=1;
    b[r + 1]-=1;
  }
  for (int i = 1; i <= n + 1; i++)
    b[i] += b[i - 1];
  for (int i = 1; i <= n; i++)
    a[i] += b[i];
  
  for (int i = 1; i <= n; i++)
    cout << a[i] << " \n"[i == n];
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
