#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int g[N][N], n, m, dx[] = {-1, 1, 0, 0} , dy[] = {0, 0, -1, 1};
bool st[N][N];

bool dfs(int x, int y, int mid) {
	if(g[x][y] > mid) return false;
	if(x == n) return true;
	for(int i = 0; i < 4; i ++) {
		int a = dx[i] + x, b = dy[i] + y;
		if(a < 1 || a > n || b < 1 || b > m) continue;
		if(st[a][b]) continue;
		st[a][b] = 1;
		if(dfs(a, b, mid)) return true;
		// st[a][b] = 0;
	}
	return false;
}

void solve() {
	cin >> n >> m;
	int l = 2e9, r = -2e9;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++) {
			cin >> g[i][j];
			l = min(g[i][j], l);
			r = max(g[i][j], r);
		}
	while(l < r) {
		memset(st, false, sizeof st);
		int mid = l + r >> 1;
		if(dfs(1, 1, mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}