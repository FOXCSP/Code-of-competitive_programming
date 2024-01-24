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

// n, k     k = C(a, 2) + C(b, 2); a + b = n
void solve(int CaseT) {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		int j = n - i;
		int now = (i - 1) * i / 2 + j * (j - 1) / 2;
		if (k == now) {
			cout << "YES\n";
			for (int t = 1; t <= i; t++)
				cout << "1 ";
			for (int t = 1; t <= j; t++)
				cout << "-1 ";
			cout << '\n';
			return ;
		}
	}
	cout << "NO\n";
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
