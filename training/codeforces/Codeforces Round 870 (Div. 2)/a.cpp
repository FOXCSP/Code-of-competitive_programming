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
  int n;
  cin >> n;
  map<int, int> mp;
  vector<int> vx;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    vx.pb(x);
    mp[x]++;
  }
  sort(all(vx));
  vx.erase(unique(all(vx)), vx.end());
  vx.pb(1e9);
  int now = 0;
  for (int i = 0; i < SZ(vx) - 1; i++) {
    now += mp[vx[i]];
    if (n - now >= vx[i] && (n - now < vx[i + 1])) {
      cout << n - now << '\n';
      return ;
    }
  }
  cout << "-1\n";
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