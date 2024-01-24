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
const int N = 31;

int w[N], g[N][N], dp[N][N], n;

void dfs(int l, int r) {
	if(l > r) return ;
	int root = g[l][r];
	cout << root << " ";
	dfs(l, root - 1), dfs(root + 1, r);
} 


void solve() {
	cin >> n;
	rep(i, 1, n) cin >> w[i];
	rep(i, 1, n) dp[i][i] = w[i], g[i][i] = i;
	rep(len, 2, n) {
		rep(i, 1, n - len + 1) {
			int j = i + len - 1;
			rep(k, i, j)
			{
				int l = k == i ? 1 : dp[i][k - 1];
				int r = k == j ? 1 : dp[k + 1][j];
				int add = l * r + w[k];
				if(add > dp[i][j]) {
					dp[i][j] = add;
					g[i][j] = k;
				}
			}
		}
	}
	cout << dp[1][n] << '\n';
	dfs(1, n);
}

int main() {
	clock_t t1 =  clock();
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
end:
	cerr << "\nTime Used:" << clock() - t1 << "ms" << '\n';
	return 0;
}