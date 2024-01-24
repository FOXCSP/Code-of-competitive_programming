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
const int N = 50, M = 350;
int dp[N][N][N][N], n, cnt[N], m;
int w[M];

void solve() {
	cin >> n >> m;
	rep(i, 1, n) cin >> w[i];
	rep(i, 1, m) {
		int x; cin >> x;
		cnt[x] ++;
	}
	dp[0][0][0][0] = w[1];
	// 枚举四个状态
	rep(a, 0, cnt[1])
		rep(b, 0, cnt[2])
			rep(c, 0, cnt[3])
				rep(d, 0, cnt[4]) {
					int r = 1 + a + b * 2 + c * 3 + d *4;// 落脚点
					int &x = dp[a][b][c][d];
					if(a) x = max(x, dp[a - 1][b][c][d] + w[r]);
					if(b) x = max(x, dp[a][b - 1][c][d] + w[r]);
					if(c) x = max(x, dp[a][b][c - 1][d] + w[r]);
					if(d) x = max(x, dp[a][b][c][d - 1] + w[r]);
				}
	cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}