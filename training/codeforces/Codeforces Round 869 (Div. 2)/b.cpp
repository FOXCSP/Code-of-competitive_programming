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
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return ;
  }
  if (n & 1) {
    cout << "-1\n";
    return ;
  }
  
  vector<int> a(n+1);
  for (int i = 0; i < n; i+=2)
    a[i + 1] = i + 2, a[i + 2] = i + 1;

  for (int i = 1; i <= n; i++) {
    cout << a[i] << " \n"[i == n];
  }
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