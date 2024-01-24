#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define pb push_back
#define all(T) T.begin(), T.end()
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const int N = 1010;
char g[N][N];
int d[N][N];
int n, m, k;
void solve(int CaseT = 1) {
	cin >> n >> m >> k;
	P(int) S, T;
	for (int i = 1; i <= n; i++) {
		cin >> g[i] + 1;
		for (int j = 1; j <= m; j++) {
			if (g[i][j] == 'S') S = {i, j};
			if (g[i][j] == 'T') T = {i, j}; 
		}
	}
	queue<array<int, 3>> que;
	que.push({0, S.fi, S.se});
	int ans = 1e9;
	int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (!que.empty()) {
		auto x = que.front();
		que.pop();
		ans = min(ans, abs(x[1]-T.fi) + abs(x[2] - T.se));
		for (int i = 0; i < 4; i++) {
			int nx = x[1] + D[i][0];
			int ny = x[2] + D[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (g[nx][ny] == '#' || d[nx][ny]) continue;
			d[nx][ny] = x[0] + 1;
			if (d[nx][ny] <= k) que.push({d[nx][ny], nx, ny});
		}
	}
	cout  << ans <<'\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
//	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
