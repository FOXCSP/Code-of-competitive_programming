#include <bits/stdc++.h>
#define int long long
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
typedef unsigned long long ull;
typedef long double ldb;
typedef double db;
mt19937_64 rnd(time(0));
// head
const int N = 1000010;
int pos[N];

vector<int> Z_algorithm(string s) {
  int n = SZ(s);
  s = "#" + s;
  int L = 1, R = 0;
  vector<int> z(n+1, 0);
  z[1] = 0;
  int px = 0;
  for (int i = 2; i <= n; i++) {
    if (i > R)
      z[i] = 0;
    else
      z[i] = min(z[i - L + 1], R - i + 1);

    while (i + z[i] <= n && s[1 + z[i]] == s[i + z[i]])
      ++z[i];

    if (z[i]) 
      pos[i] = max(pos[i], i - 1);
    else if (px + z[px] - 1 >= i) 
      pos[i] = max(pos[i], px - 1);

    if (i + z[i] - 1 > R)
      L = i, R = i + z[i] - 1;
    // else if (i + z[i] - 1 == R)
    px = i;
  }
  return z;
}

vector<int> kmp(string s) {
  int n = SZ(s);
  s = "#" + s;
  vector<int> nxt(n + 1, 0);
  nxt[1] = 0;
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && s[i] != s[j+1])
      j = nxt[j];
    if (s[i] == s[j+1])
      ++j;
    nxt[i] = j;
  }
  return nxt;
}


void solve(int CaseT) {
  int n;
  string s;
  cin >> n >> s;
  auto z = Z_algorithm(s);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += pos[i];
  }



  // auto nxt = kmp(s);
  // ll ans = 0;
  // for (int i = 1; i <= n; i++) {
  //   int j = i;
  //   while (nxt[j])
  //     j = nxt[j];
  //   if (nxt[i])
  //     nxt[i] = j;
  //   ans+=i-j;
  // }

  // for (int i = 1; i <= n; i++)
  //   cout << nxt[i] << " \n"[i == n];
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}

