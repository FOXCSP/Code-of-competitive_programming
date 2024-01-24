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
mt19937_64 rnd(time(0));
typedef long long ll;
typedef long double ldb;
typedef double db;
// head

const int N = 100010;
const ll mod = 1000000007;

ll qmi(ll a, ll b) {
  ll ans = 1;
  for (; b; b >>= 1) {
    if (b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
  }
  return ans;
}

void solve(int CaseT) {
  ll a, b;
  cin >> a >> b;
  cout << qmi(a, b) << '\n';
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _=1;
  // cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}