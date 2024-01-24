#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
using ll = long long;
typedef double db;
typedef long double ldb;
// 开根号请使用    sqrtl 谢谢  sb sqrt 已死

// -- head--
const int N = 110;
int dp[N][N][1200];
const int mod = 1e9+7;
int n, m;
void solve(int CaseT) {
    cin >> n >> m;
    dp[0][0][2] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= (1024); k++) {
                if (k&&k%2==0) dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k/2]) % mod;
                dp[i][j + 1][k] = (dp[i][j + 1][k] + dp[i][j][k+1]) % mod;
            }
        }
    }
    cout << dp[n][m][0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    // cin >> _;
    for (int i = 1; i <= _; i++) {
        solve(i);
    }
    return 0;
}