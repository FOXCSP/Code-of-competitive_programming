#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = N * N;
int g[N][N], n, m, p[M], idx, ans;

int find(int x) { return p[x] != x ? p[x] = find(p[x]) : x; }

void solve() {
	cin >> m >> n;
	int a, b, c, d;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			g[i][j] = ++ idx;

	for(int i = 1; i <= n * n; i ++) p[i] = i;
	while(cin >> a >> b >> c >> d) {
		int x = g[a][b], y = g[c][d];
		int px = find(x), py = find(y);
		if(px != py) {
			p[py] = px;
		}
	}
	
	for(int j = 1; j <= n; j ++) {
		for(int i = 1; i < n; i ++) {
			int x = g[i][j], y = g[i + 1][j];
			int px = find(x), py = find(y);
			if(px != py) {
				p[py] = px;
				ans += 1;
			}
		}
	}
	
	for(int i = 1;i <= n; i ++) {
		for(int j = 1; j < n; j ++) {
			int x = g[i][j], y = g[i][j + 1];
			int px = find(x), py = find(y);
			if(px != py) {
				p[py] = px;
				ans += 2;
			}
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}