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
ll pw1[N], pw2[N];
ll Hs[N], Hs1[N], Hs2[N], Hs3[N], Hs4[N];

pair<ll, ll> get1(int l, int r) {
  return {
    ((Hs1[r] - Hs1[l - 1] * pw1[r - l + 1]) % mod1 + mod1) % mod1, 
    ((Hs2[r] - Hs2[l - 1] * pw2[r - l + 1]) % mod2 + mod2) % mod2};
}

pair<ll, ll> get2(int l, int r) {
  return {
    ((Hs3[r] - Hs3[l - 1] * pw1[r - l + 1]) % mod1 + mod1) % mod1, 
    ((Hs4[r] - Hs4[l - 1] * pw2[r - l + 1]) % mod2 + mod2) % mod2};
}

void solve(int CaseT) {
  string s, p;

  cin >> s >> p;
  int n = SZ(s), m = SZ(p);
  string ss = "#" + s + p;
  // 

  pw1[0] = pw2[0] = 1;
  for (int i = 1; i <= 1000000; i++) 
    pw1[i] = (pw1[i - 1] * base1) % mod1,
    pw2[i] = (pw2[i - 1] * base2) % mod2;
  for (int i = 1; ss[i]; i++)
    Hs1[i] = (Hs1[i - 1] * base1 % mod1 + ss[i]) % mod1,
    Hs2[i] = (Hs2[i - 1] * base2 % mod2 + ss[i]) % mod2;

  string ans = "";
  int len = 0;
  int step = 1;
  for (auto x : s) {
    ans.pb(x);
    Hs3[len + 1] = (Hs3[len] * base1 % mod1 + x) % mod1;
    Hs4[len + 1] = (Hs4[len] * base2 % mod2 + x) % mod2;
    len++;
    if (len >= m) {
      if (get2(len - m + 1, len) == get1(n + 1, n + m)) {
        len -= m;
        len = max(0, len);
        for (int i = 0; i < m; i++)
          ans.pop_back();
      }
    }
  }
  cout << ans << '\n';
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
