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

const int N = 110;

void solve(int CaseT) {
  int n, k;
  cin >> n >> k;
  vector<string> str;
  for (int i = 1; i <= n; i++) {
    string x;
    cin >> x;
    str.pb(x);
  }
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (str[0] == str[i]) 
      ans++;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
	int _;
  _=1;
  cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}

