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

void solve(int CaseT) {
  int h, w, xa, ya, xb, yb;
  cin >> h >> w >> xa >> ya >> xb >> yb;
  auto check = [&]() {
    bool f = 1;
    pair<int, int> a = {xa, ya};
    pair<int, int> b = {xb, yb};
    if (ya > yb) {
    }
  };
  if (xa >= xb || abs(ya - yb) > 2 || (xa == xb - 1 && !(abs(ya-yb) <= 1))) cout << "Draw\n";
  else {
    if (abs(xa - xb) & 1) cout << "Alice\n";
    else if (abs(ya - yb) == 2 && (ya < w || ya > 1)) cout << "Draw\n";
    else if (check()) {
      cout << "Draw\n";
    }
    else cout << "Bob\n";
  } 

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