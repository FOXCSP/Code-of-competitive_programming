#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

const int N = 110;
int f[N][N][N], n, m;
int  w[110], g[N][N][N];

void solve () {
	cin >> n >> m;
	for(int i = 1;i <= n; i ++) {
		cin >> w[i];
		w[i] = (w[i] % 10 + 10) % 10;
		w[i + n] = w[i];
	}
	memset(f, 0xcf, sizeof f);
	memset(g, 0x3f, sizeof g);
	for(int i = 1;i <= n * 2; i ++) w[i] += w[i - 1];
	for(int len = 1; len <= n; len ++) {
		for(int l = 1; l + len - 1 <= n * 2; l ++) {
			int r = l + len - 1;
			f[l][r][1] = g[l][r][1] = (w[r] - w[l - 1]) % 10;
			for(int k = 2; k <= m; k ++) {
				for(int x = l + k - 2; x <= r - 1; x ++) {
					f[l][r][k] = max(f[l][r][k], f[l][x][k - 1] * ((w[r] - w[x]) % 10));
					g[l][r][k] = min(g[l][r][k], g[l][x][k - 1] * ((w[r] - w[x]) % 10));
					// cout << g[l][x][k - 1] * ((w[r] - w[x]) % 10)<< " hhhhh\n";
				}
			}
		}
	}
	pii res = {2e9, -2e9};
	for(int i = 1; i <= n; i ++) {
		res.fi = min(res.fi, g[i][i + n - 1][m]);
		res.se = max(res.se, f[i][i + n - 1][m]);
	}
	cout << res.fi << "\n" << res.se << '\n';
}


signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}