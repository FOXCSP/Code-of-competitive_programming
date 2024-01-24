#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T>
#define fi first
#define se second
#define vec vector
#define pb push_back
using namespace std;
using ll = long long;

const int N = 26;
int dp[N][N][N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dp[0][0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int x1 = 0; x1 <= n / 4; x1++) {
            for (int x2 = 0; x2 <= n / 4; x2++) {
                for (int x3 = 0; x3 <= n / 4; x3++) {
                    for (int x4 = 0; x4 <= n / 4; x4++) {
                        int &x = dp[x1][x2][x3][x4];
                        if (x1 < n / 4) dp[x1 + 1][x2][x3][x4] = max(dp[x1 + 1][x2][x3][x4], x + a);
                        if (x2 < n / 4) dp[x1][x2 + 1][x3][x4] = max(dp[x1][x2 + 1][x3][x4], x + b);
                        if (x3 < n / 4) dp[x1][x2][x3 + 1][x4] = max(dp[x1][x2][x3 + 1][x4], x + c);
                        if (x4 < n / 4) dp[x1][x2][x3][x4 + 1] = max(dp[x1][x2][x3][x4 + 1], x + d);
                    }
                }
            }
        }
    }
    cout << dp[n/4][n/4][n/4][n/4] << '\n';
    return 0;
}