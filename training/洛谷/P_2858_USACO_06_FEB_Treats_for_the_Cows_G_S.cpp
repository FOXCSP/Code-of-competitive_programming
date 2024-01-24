#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define pb push_back
#define rp (p<<1|1)
#define lp (p<<1)
#define endl '\n'
#define fi first
#define se second
// #define int long long

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 2010;
int dp[N][N];
int n, w[N];
void solve() {
    cin >> n;
    for(int i = 1;i <= n; i ++) cin >> w[i];
    for(int i = 1;i <= n; i ++) dp[i][i] = n * w[i];
    for(int l = 2; l <= n;l ++)
        for(int i = 1; i + l - 1 <= n; i ++)
        {
            int j = i + l - 1;
            dp[i][j] = max(dp[i + 1][j] + w[i] * (n - l + 1), dp[i][j - 1] + w[j] * (n - l + 1));
            // 用小区间更新大区间, 初始化支持
            // 对于 大区间 [i, j], 他的上一个小区间要么是 [i + 1][j], 要么是[i][j - 1]
            // 至于乘积, 最大的区间为n, 长度为 l 的区间的下一个操作是第 (n - l + 1) 次
        }
    cout << dp[1][n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
