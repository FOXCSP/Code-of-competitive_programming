#include <bits/stdc++.h>
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
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--
const int N = 100010, inf = 1e9;
vec<int> e[N];
void solve(int CaseT) {
    int n, m;
    cin >> n >> m;
    vec<string> vs;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        vs.pb(s);
    }
    vec<vec<int>> dp(n+1,vec<int>(2,inf));
    dp[1][0] = dp[n][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < SZ(vs[i-1]); j++) {
            if (vs[i-1][j] == '1') {
                if (i+j+1<=n) 
                    dp[i+j+1][0] = min(dp[i+j+1][0], dp[i][0]+1);
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < SZ(vs[i-1]); j++) {
            if (vs[i-1][j] == '1') {
                if (i+j+1<=n) 
                    dp[i][1] = min(dp[i][1], dp[i+j+1][1]+1);
            }
        }
    }

    // cout << "-1\n";

    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i][0] << " " << dp[i][1] << '\n';
    // }

    for (int k = 2; k < n; k++) {
        int l = max(1, k - m);
        int r = min(n, k + m);
        int ans = inf;
        for (int i = l; i < k; i++) {
            for (int j = k + 1; j <= r; j++) {
                if (j - i - 1 < m) {
                    if (vs[i-1][j-i-1] == '1') 
                        ans = min(ans, dp[i][0] + dp[j][1] + 1);
                }
            }
        }
        cout << (ans == inf ? -1:ans) << " ";
    }

}

int main() {
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