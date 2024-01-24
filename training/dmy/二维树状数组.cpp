#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 510;
ll c[N][N], a[N][N];
int n, m;

void modify(int x, int y, ll d) {
	for (int p = x; p <= n; p += p & (-p))
		for (int q = y; q <= m; q += q & (-q))
			c[p][q] += d;
} // 给(x, y)加上d

ll query(int x, int y) {
	ll s = 0;
	for (int p = x; p; p -= p & (-p))
		for (int q = y; q; q -= q & (-q))
			s += c[p][q];
	return s;
} // 查询(1, 1)-(x, y)的前缀和

void solve () {
	int q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
			modify(i, j, a[i][j]);
		}
	}

	while (q --) {
		int op; cin >> op;
		if (op == 1) {
			int x, y;
			ll d; 
			cin >> x >> y >> d;
			modify(x, y, d - a[x][y]);
			a[x][y] = d;
		}
		else {
			int x, y; cin >> x >> y;
			cout << query(x, y) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}