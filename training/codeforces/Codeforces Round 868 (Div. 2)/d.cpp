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

const int N = 200010;
int n, k;
int x[N], c[N];

void solve(int CaseT) {
	cin >> n >> k;
	
	for (int i = 1; i <= k; i++)
		cin >> x[i];
	
	for (int i = 1; i <= k; i++)
		cin >> c[i];
	
	for (int i = 1; i <= k; i++) {
		int m = x[i] - x[i - 1];
		int d = c[i] - c[i - 1];
		if (i == 1)
			d -= 3,
			m -= 3;
		
		if (m < d) {
			cout << "NO\n";
			return ;
		}
	}
	
	// k <= 20, 对于每个 x[i], c[i], 都可以找到一个单独的 char 来提供 c[i] - c[i - 1]的贡献
	
	string ans = "abc";
	char pp = 'c';
	
	for (int i = 1; i <= k; i++) {
		int m = x[i] - x[i - 1];
		int d = c[i] - c[i - 1];
		if (i == 1)
			d -= 3,
			m -= 3;
		// abc   abcdddd
		while (m > d) {
			pp = (pp == 'c') ? 'a' : pp + 1;
			ans.pb(pp);
			m--;
		}
		
		char now = 'c' + i;
		while (SZ(ans) < x[i] && d) {
			ans.pb(now);
			d--;
		}
	}
	
	cout << "YES\n";
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

/*
1
10 2
5 10
5 6

1
7 5
3 4 5 6 7
3 3 3 4 4

*/
