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
int n, m;
char a[N][N], b[N][N], bk[N][N];

bool ok(char x) {
	return x == '#';
}

void solve(int CaseT) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i] + 1;
	vec<int> ans(max(n, m) + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ok(a[i][j]) && ok(a[i - 1][j - 1]) && ok(a[i - 1][j + 1]) && ok(a[i + 1][j + 1]) && ok(a[i + 1][j - 1])) {
				int d = 0;
				int p = i, q = j;
				while (p - 1 && q - 1 && ok(a[p - 1][q - 1])){
					d++, p--, q--;
//					cout << " error\n";
				}
				ans[d]++;
			}
		}
	} 
	for (int i = 1; i <= min(n, m); i++)
		cout << ans[i] << " \n"[i == min(n, m)];
}

int main() {
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

