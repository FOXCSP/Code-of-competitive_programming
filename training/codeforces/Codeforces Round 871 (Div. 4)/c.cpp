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
  map<string, int> mp;
  for (int i = 1; i <= n; i++) {
    int m;
    string s;
    cin >> m >> s;
    if (mp.count(s) == 0)  mp[s] = m;
    else mp[s] = min(mp[s], m);
  }
  int m1 = mp["01"];
  int m2 = mp["10"];
  int m3 = mp["11"];
  int ans = 1 << 30;
  if (m1 && m2) {
    ans = min(ans, m1 + m2);
  }
  if (m1 && m3) {
    ans = min(ans, m1 + m3);
  }
  if (m2 && m3) {
    ans = min(ans, m2 + m3);
  }
  if (m3) {
    ans = min(ans, m3);
  }
  if (ans == (1 << 30)) {
    cout << "-1\n";
  } else {
    cout << ans << '\n';
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