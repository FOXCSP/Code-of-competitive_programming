#include <bits/stdc++.h>

using namespace std;

const int N = 2010, mod = 1e8;

int f[2][N], w[N];
int n, m;
void solve() {
	cin >> n >> m;

	for(int i = 1;i <= n; i ++) {
		cin >> w[i];
	}
	f[0][0] = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j < m; j ++)
			f[i & 1][j] = (f[(i - 1) & 1][j] + f[(i - 1) & 1][((j - w[i]) % m + m) % m]) % mod;
	
	cout << f[(n) & 1][0] - 1 << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}