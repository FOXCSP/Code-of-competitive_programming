#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define fi first
#define se second
#define pb push_back
#define SZ(xyz) xyz.size()
#define rep(i, l, r) for(int i = l; i <= (r); i ++)
#define lep(i, r, l) for(int i = r; i >= (l); i --)
// #define int long long
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 200010, M = 3000010;

int dp[N], n, maxn;
std::vector<int> a[M];
void solve() {
	cin >> n;
	rep(i, 1, n) {
		int x, y;
		cin >> x >> y;
		a[y].pb(x);
		maxn = max(maxn, y);
	}
	// 区间左端点 = l
	// f[i] = max(f[i-1], max(f[l - 1]) + (j - (l - 1)))
	rep(i, 1, maxn) {
		dp[i] = dp[i - 1];
		// for(int j = 0; j < a[i].size(); j ++) {
		// }
		// rep(j, 0, SZ(a[i]) -1 ) {

		// }
		for(int j = 0; j < -1; j ++) {

		}
	}
	cout << dp[maxn] << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}