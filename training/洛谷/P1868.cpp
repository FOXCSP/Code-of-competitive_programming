#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define fi first
#define se second
#define pb push_back
// #define int long long
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 200010, M = 3000010;

int dp[M], n, maxn;
std::vector<int> a[M];
void solve() {
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		int x, y;
		cin >> x >> y;
		a[y].pb(x);
		maxn = max(maxn, y);
	}
	// 区间左端点 = l
	// f[i] = max(f[i-1], max(f[l - 1]) + (j - (l - 1)))
	for(int i = 1;i <= maxn; i ++) {
		dp[i] = dp[i - 1];
		int x = 0;
		for(int j = 0; j < a[i].size(); j ++)
			x = max(x, dp[a[i][j] - 1] + i - a[i][j] + 1);
		dp[i] = max(dp[i], x);
	}
	cout << dp[maxn] << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}