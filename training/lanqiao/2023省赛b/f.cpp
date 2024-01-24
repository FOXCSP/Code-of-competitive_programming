#include <bits/stdc++.h>
#define int long long
#define vec vector
#define se second
#define fi first
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;

const int N = 10010, inf = 1e9;
char s[20][20];
int g[20][20];
int ans = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 0};
int n, m;
void bfs(int x, int y) {
	queue<P(int)> que;
	que.push({x, y});
	while (SZ(que)) {
		P(int) t = que.front();
		que.pop();
		g[t.fi][t.se] = 1;
		for (int i = 0; i < 4; i++) {
			int x = t.fi + dx[i];
			int y = t.se + dy[i];
			if (x < 0 || x > n || y < 0 || y > m) continue;
			if (g[x][y]) continue;
			que.push({x, y});
		}
	}
}

void solve (int Case) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] + 1;
	}
	for (int i= 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (g[i][j] == 0) bfs(i, j), ans++;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
	cin >> _; 
	for (int i=1; i<=_;i++) {
		solve(i);
	}
	return 0;
}
