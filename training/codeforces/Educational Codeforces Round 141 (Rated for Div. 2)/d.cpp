#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 998244353;
const int N = 310, D = 300 * 301;
int f[N][N], a[N];
int n, m;
void C(int& x) {
	if (x > mod) x -= mod;
	if (x < 0) x += mod;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		for (int j = -D + 1; j <= D; j++) {
			if (j) {
				f[i + 1][a[i + 1] - j + D] += f[i][j + D]; C(f[i + 1][a[i + 1] - j + D]);
				f[i + 1][a[i + 1] + j + D] += f[i][j + D]; C(f[i + 1][a[i + 1] + j + D]);
			} else {
				f[i + 1][a[i + 1] - j + D] += f[i][j + D];
			}
		}
	}
	int ans = 0;
	for (int i = -D + 1; i <= D; i++) ans = (ans + f[n][i + D]) % mod;
	cout << ans << '\n';
	return 0;
}