#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define setdb cout<<fixed<<setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

const int N = 510, inf = 1 << 30;

int n, m, k;
int d[N][N];
int dp[N][14];

vec<array<int, 3>> edge;


void solve(int CaseT) {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = inf;


    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // int p = min(w, d[u][v]);
        // d[u][v] = d[v][u] = p;
        edge.pb({u, v, w});
        edge.pb({v, u, w});

    }

    for (int i = 1; i <= n; i++)
        for (int t = 0; t <= k; t++)
            dp[i][t] = inf;

    dp[1][k] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < SZ(edge); j++) {
            int u = edge[j][0];
            int v = edge[j][1];
            int w = edge[j][2];
            for (int t = 0; t <= k; t++) {
                dp[v][t] = min(dp[v][t], dp[u][t] + w);
                if (t) dp[v][t-1] = min(dp[v][t-1], dp[u][t] + w / 2); 
            }
        }
    }

    // dp[1][k] = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (i == j) continue;
    //         if (d[i][j] == inf) continue;
    //         for (int t = 0; t <= k; t++) {
    //             dp[j][t] = min(dp[j][t], dp[i][t] + d[i][j]);
                
    //             if (t + 1 <= k) 
    //                 dp[j][t] = min(dp[j][t], dp[i][t + 1] + d[i][j]/2); 
    //         }
    //     }
    // }

    int ans = 1 << 30;
    // cout << dp[2][k] << '\n';
    // cout << dp[2][k-1] << '\n';
    // cout << dp[3][k-2] << '\n';
    // cout << dp[n][k] << '\n';
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';
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