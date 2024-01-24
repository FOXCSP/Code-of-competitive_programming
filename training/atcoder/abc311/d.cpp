#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 210;
const ll mod = 998244353;

int n, m;
char g[N][N];
bool st[N][N][4], d[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> g[i] + 1;
	memset(st, 0, sizeof st);

	queue<array<int, 3>> q;

	int sta[] = {0, 1, 2, 3}; // 右下左上
	int D[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	q.push({2, 2, 0});
	q.push({2, 2, 1});

	while (!q.empty()) {
		auto x = q.front(); q.pop();
		int nx = x[0] + D[x[2]][0], ny = x[1] + D[x[2]][1];
		d[x[0]][x[1]] = 1;
		if (g[nx][ny] == '#') {
			for (int i = 0; i < 4; i++) {
				if (!st[x[0]][x[1]][i]) {
					st[x[0]][x[1]][i] = 1;
					q.push({x[0], x[1], i});
				}
			}
		} else {
			st[nx][ny][x[2]] = 1;
			q.push({nx, ny, x[2]});
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += d[i][j];
	cout << ans << '\n';

	return 0;
}
