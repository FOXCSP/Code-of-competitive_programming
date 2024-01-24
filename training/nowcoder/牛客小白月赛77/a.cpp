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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a;
  vector<int> vx;
  while (cin >> a) {
    vx.pb(a);
  }
  cout << (((vx[0] != vx[3]) + (vx[1] != vx[2]) < 2) ? "YES" : "NO") << '\n';
  return 0;
} 
