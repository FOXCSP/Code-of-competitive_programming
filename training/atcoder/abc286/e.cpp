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
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

const ll N = 310, inf = 1e15;
P(ll) g[N][N];
ll a[N];
char s[N][N];
void solve(int CaseT) {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j].fi = inf;
        }
    }
    
    for (int i = 1; i <= n; i++) g[i][i] = {0, 0};
    
    for (int i = 1; i <= n; i++) {
        cin >> s[i] + 1;
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == 'Y') g[i][j].fi = 1, g[i][j].se = a[j];
        }
    }

    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j ||j == t || i == t) continue;
                if (g[i][j].fi > g[i][t].fi + g[t][j].fi) {
                    g[i][j].fi = g[i][t].fi + g[t][j].fi;
                    g[i][j].se = g[i][t].se + g[t][j].se;
                } else if (g[i][j].fi == g[i][t].fi + g[t][j].fi) {
                    g[i][j].se = max(g[i][j].se, g[i][t].se + g[t][j].se);
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (g[i][j].fi == inf) cout << "0" << " \n"[i == n];
    //         else cout << g[i][j].fi << " \n"[j == n];
    //     }
    // }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << g[i][j].se << " \n"[j == n];
    //     }
    // }

    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (g[u][v].fi == inf) cout << "Impossible\n";
        else cout << g[u][v].fi << " " << g[u][v].se+a[u] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    setdb;
    // cin >> _;
    for (int i = 1; i <= _; i++) {
        solve(i);
    }
    return 0;
}