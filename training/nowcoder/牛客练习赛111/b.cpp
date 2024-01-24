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
  string a, b;
  cin >> n >> a >> b;
  int res = 0;
  string x = a, y = b;
  sort(all(x));
  sort(all(y));
  map<char, int> mp;
  for (int i = 0; i < n; i++)
    res += (a[i] != b[i]),
    mp[a[i]]++;
  if (res > 2 || x != y) {
    cout << "NO\n";
  } else {
    if (res == 2) cout << "YES\n";
    if (res == 1) cout << "NO\n";
    else {
      if (SZ(mp) < n) cout << "YES\n";
      else cout << "NO\n";
    }
  }
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
