#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200010, M = 500;
int n, q;
ll sum[M + 10][M + 10];
vector<ll> large, p[N];
void solve() {
	cin >> n >> q;
	for (int _ = 1; _ <= q; _++) {
		int op; cin >> op;
		if (op == 1) {
			int x, y; cin >> x >> y;
			int m = p[x].size();
			if (m <= M) {
				for (int i = 0; i < m; i++) sum[m][i] -= p[x][i];
			}
			p[x].push_back(y);
            ++m;
			if (m <= M) {
				for (int i = 0; i < m; i++) sum[m][i] += p[x][i];
			} else if(m == M + 1) large.push_back(x);
		} else {
			int z; cin >> z;
			ll ans = 0;
			for (int i = 1; i <= M; i++) {
				ans += sum[i][z % i];
			}
			for (int c : large) {
				ans += p[c][z % (int)p[c].size()];
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