#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define pb push_back
#define all(T) T.begin(), T.end()
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const int N = 1010;
int n, m;
int s[N][N], c[N][N], a[N], b[N];

void solve(int CaseT = 1) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i  =1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c[i][j] = a[i] * b[j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			s[i][j] = c[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	
	int q;
	cin >> q;
	for (; q--; ) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]) <<'\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
