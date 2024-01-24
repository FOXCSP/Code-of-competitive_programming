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
typedef long double lbd;
// head

const ll N = 2000010;
const ll mod1 = 998244353, base1 = 2333;
const ll mod2 = 1000000007, base2 = 1009;

auto KMP(string s) {
  int n = SZ(s);
  s = "#" + s;
  vector<int> nxt(n + 1, 0);
  nxt[1] = 0;
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && s[i] != s[j + 1])
      j = nxt[j];
    if (s[i] == s[j + 1])
      j++;
    nxt[i] = j;
  }
  return nxt;
}

void solve(int CaseT) {
  string s;
  cin >> s;
  int n = SZ(s);
  auto nxt = KMP(s);
  for (int i= 1; i <= n; i++) {
    cout << nxt[i] << " ";
  }
  cout << '\n';
  cout << n - nxt[n] << '\n';
}	

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _ = 0;
  _=1;
  //  cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
