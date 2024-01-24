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

void solve(int CaseT) {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1\n";
		return ;
	}
	if (n & 1) {
		cout << "-1\n";
	} else{
		vec<int> b(n + 1, 0);
		b[1] = 0, b[2] = n - 1;
		int l = 0, r = n - 1;
		for (int i = 3; i <= n; i++) {
			if (i & 1) b[i] = ++l;
			else b[i] = --r;
		}
		vec<int> a(n + 1, 0);
		a[1] = n, a[2] = n - 1;
		for (int i = 3; i <= n; i++) {
			if (b[i] > b[i - 1]) a[i] = (b[i] - b[i - 1]);
			else a[i] = b[i] + n - b[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " \n"[i == n];
		}
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
