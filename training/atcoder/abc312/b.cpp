#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 110;
const ll mod = 998244353;

char g[N][N];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> g[i] + 1;

	auto ck = [&](int x, int y) {
		for (int i = x; i <= x + 3; i++)
			for (int j = y; j <= y + 3; j++) {
				if (i <= x + 2 && j <= y + 2 && g[i][j] != '#')   return false;
				if (i == x + 3 || j == y + 3) if (g[i][j] != '.') return false;
			}
		for (int i = x + 5; i <= x + 8; i++)
			for (int j = y + 5; j <= y + 8; j++) {
				if (i == x + 5 || j == y + 5) if (g[i][j] != '.') return false;
				if (i > x + 5 && j > y + 5)  if (g[i][j] != '#') return false;
			}
		return true;
	};

	for (int i = 1; i + 8 <= n; i++)
		for (int j = 1; j + 8 <= m; j++) {
			if (ck(i, j)) {
				cout << i << " " << j << '\n';
			}
		}

	return 0;
}
