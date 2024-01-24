#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int g[110][110], d[110][110];
void solve() {
	cin >> n >> m;
	memset(d, 0x3f, sizeof d);
	for(int i = 1; i <= m; i ++) {
		int a, b, c; cin >> a >> b >> c;
		g[a][b] = g[b][a] = c;
		d[a][b] = d[b][a] = c;
	}
	int ans = inf;
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
			{
				if(i != j && g[i][k] && g[k][j]) 
					ans = min(ans, d[i][j] + g[i][k] + g[k][j]);
				if(d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
	if(ans == inf) cout << "No solution.\n";
	else cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}