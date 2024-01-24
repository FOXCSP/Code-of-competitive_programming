#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200010, M = 500;
int n, m, q;
ll tag[M + 10][M + 10], val[N];
void solve() {
	cin >> n >> q;
	for (int i = 0;i < q; i++) {
		int op, x;
		cin >> op >> x;
		if (op == 1) {
			int y, d;
			cin >> y >> d;
			if (x <= M) {
				tag[x][y] += d;
			} else {
				for (int j = y; j <= n; j += x) {
					val[j] += d;
				}
			}
		} else {
			ll ans = val[x];
			for (int j = 1; j <= M; j++) {
				ans += tag[j][x%j];
			}
			cout << ans << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}