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
  map<int, int> mp;
  vector<int> vs;
  for (int i = 0; i < 4; i++) {
    int x, y;
    cin >> x >> y;
    if (mp.count(x) != 0) vs.pb(abs(mp[x] - y));
    else mp[x] = y;
  }
  cout << vs[0] * vs[1] << '\n';
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