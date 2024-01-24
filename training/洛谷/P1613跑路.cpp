#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 55, M = 20010;

ll r[N][64], re[N], n, m;

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		ll a, b; cin >> a >> b;
		r[a][0] |= (1ll << b);
		re[a] |= (1ll << b);
	}
	// r[a][k] = r[a][k - 1] |
	for(int j = 1; j < 60; j ++) {
		for(int i = 1; i <= n; i ++) {
			ll staus = r[i][j - 1], tmp = 0;
			for(int k = 1; k <= n; k ++)
				if((1ll << k) & staus)
					tmp |= r[k][j - 1];
			r[i][j] = tmp;
			re[i] |= tmp;
		}
	}

	int ans = 0;
	ll tmp = 2;
	while(!(tmp & (1ll << n))) {
		ll res = tmp;
		for(int i = 1; i <= n; i ++)
			if((1ll << i) & tmp)
				res |= re[i];
		tmp = res;
		ans ++;
	}
	cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}