#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 110, mod = 998244353;
ll c[N][N];
ll a[N],b[N];
void init()
{
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) c[i][j] = 1ll;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	a[2] = 1; b[2] = 0;
	for(int i = 4; i <= 60; i += 2) {
		a[i] = (b[i - 2] + c[i - 1][i/2]) % mod;
		b[i] = (c[i][i/2] - a[i] - 1 + mod ) % mod;
	}
}
void solve() {
	int n;
	cin >> n;
	ll y = c[n][n/2] - 1;
	cout << a[n] << " " << y - a[n] << " " << 1 << '\n';
}

int main () {
	init();
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}