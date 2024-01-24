#include <bits/stdc++.h>
#define fi first
#define se second
#define all(T) T.begin(), T.end()
#define pb emplace_back
#define SZ(T) (int)(T.size())
#define lp (p<<1)
#define rp (p<<1|1)
#define P(T) pair<T,T>
#define setop(T) cout<<fixed<<setprecision(T);
using namespace std;
using ll = long long;

const int N = 4010, M = 1000010;
int dp[2][N][N];
int vis[M], a[N], prime[M], cnt;
const ll mod = 998244353;




void solve(int caseT) {
	int n, mx = 0;
	cin >> n;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				dp[i][j][k] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for (int i = 2; i <= mx; i++) {
		if (!vis[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= mx; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n * 2; j++) {
			for (int k = 1; k <= n; k++) {
				if (k > i) continue;
				if (!vis[a[j]]) {
					if (n - k + 1 > 0) 
						dp[i&1][j][k] = (dp[i&1][j][k]  + dp[!(i&1)][j - 1][k - 1] + (n - k + 1)) % mod;
				} else {
					if (n - k > 0)
						dp[i&1][j][k] = (dp[i&1][j][k] + dp[!(i&1)][j - 1][k] + (n - k)) % mod;
				}
			}
		}
	}
	// dp[n&1][n * 2][k];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + dp[n & 1][n * 2][i]) % mod;
	}
	cout << ans << '\n';
}


int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _;
	_=1;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
