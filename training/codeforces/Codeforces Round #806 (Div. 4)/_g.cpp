#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 100010;
int n;
ll a[N], k, inf = 2e18;
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(35, -inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = a[i] - k;
        dp[i][0] += dp[i - 1][0];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 30; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (a[i] >> j));
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] >> j) - k);
            // dp[i][30] = max(dp[i][30], dp[i - 1][30]);
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) 
    for (int j = 0; j <= 30; j++) 
    res = max(res, dp[i][j]);
    cout << res << '\n';
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    // cout << ((int)(1e9) >> 30) << '\n';
    return 0;
}