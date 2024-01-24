#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 3010;
const ll mod = 998244353;

int n, m, q;
ll g[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			g[i][j] = 1;

	for (; q--; ) {
		int x, y;
		cin >> x >> y;
		g[x][y] = 0;
	} 

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (g[i][j] == 0) continue;
			int x = g[i - 1][j], y = g[i][j - 1], z = g[i - 1][j - 1];
			g[i][j] = min({x, y, z}) + 1;
		}

	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= m; j++)
	// 		cout << g[i][j] << " \n"[j == m];

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += g[i][j];
	cout << ans << '\n';
	return 0;
}
