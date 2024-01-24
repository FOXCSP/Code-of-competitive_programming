#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

const int N = 25010;
int n, m;
vector<int> a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		int x;
		int x1 = 2e9, x2 = 2e9;
		for (int j = 1; j <= m; j++) {
			cin >> x;
			if (x1 > x) x2 = x1, x1 = x;
			else if (x2 > x) x2 = x;
		}
		a[i].pb(x1);
		a[i].pb(x2);
	}
	sort(a + 1, a + n + 1, [&] (vector<int> x, vector<int> y) {
		return x[1] < y[1];
	});
	long long ans = 0;
	int cur = 2e9;
	for (int i = n; i >= 2; i--) {
		ans += a[i][1];
		cur = min(cur, a[i][0]);
	}
	ans += min(cur, a[1][0]);
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) a[i].clear();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	cin >> _;

	while (_--) {
		solve();
	}
	return 0;
} 
