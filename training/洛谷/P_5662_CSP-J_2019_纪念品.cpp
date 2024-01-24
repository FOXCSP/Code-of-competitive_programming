#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define fi first
#define se second
#define pb push_back
#define SZ(a) a.size()
#define rep(i, l, r) for(int i = l; i <= r; i ++)
#define lep(i, r, l) for(int i = r; i >= l; i --)
// #define int long long
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 110, M = 10010;
int w[N][N];
int n ,m, t;
int dp[10010];
void solve() {
	cin >> t >> n >> m;
	for(int i = 1;i <= t; i ++)
		for(int j = 1; j <= n; j ++)
			cin >> w[i][j];
	for(int i = 1;i < t; i ++) {
		memset(dp, 0, sizeof dp);
		for(int j = 1; j <= n; j ++)
			if(w[i + 1][j] > w[i][j])
				for(int k = w[i][j]; k <= m; k ++)
					dp[k] = max(dp[k], dp[k - w[i][j]] + w[i + 1][j] - w[i][j]);
		m += dp[m];
	}
	cout << m << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}