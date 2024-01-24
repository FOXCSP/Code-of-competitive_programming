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

const int N = 31;
int n, m;
char a[N][N], b[N][N], bk[N][N];

void trans(int s, int t) {
	while (s--) {
		for (int i = 1; i <= m; i++) {
			char ch = a[1][i];
			for (int j = 1; j < n; j++)
				a[j][i] = a[j + 1][i];
			a[n][i] = ch;
		}
	}
	while (t--) {
		for (int i = 1; i <= n; i++) {
			char ch = a[i][1];
			for (int j = 1; j < m; j++) {
				a[i][j] = a[i][j + 1];
			}
			a[i][m] = ch;
		}
	}
}

bool ck() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] != b[i][j])
				return false;
	return true;
}

void solve(int CaseT) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> bk[i]+1;
	for (int i = 1; i <= n; i++)
		cin >> b[i]+1;
	for (int s = 1; s <= n; s++) {
		for (int t = 1; t <= m; t++) {
			memcpy(a, bk, sizeof bk);
			trans(s, t);
			if (ck()) {
				cout << "Yes\n";
				return ;
			}
		}
	}
	cout << "No\n";
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

