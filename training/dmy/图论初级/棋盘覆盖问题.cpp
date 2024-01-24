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
// n < 40, m < 800;
vec<int> e[801];
int n, m;
int id[801], vis[801], r[41][41], n1, n2;
int g[41][41];

bool find(int u) {
    vis[u] = 1;
    for (auto v : e[u]) {
        if (!id[v] || (!vis[id[v]] && find(id[v]))) {
            id[v] = u;
            return true;
        }
    }
    return false;
}

int match() {
    int ans = 0;
    for (int i = 1; i <= n1; i++) {
        memset(vis, false, sizeof vis);
        if (find(i))
            ans++;
    }
    return ans;
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
    }

    int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!g[i][j]) {
                if ((i + j) & 1)
                    r[i][j] = ++n2;
                else
                    r[i][j] = ++n1;
            }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!g[i][j] && (i + j) % 2 == 0)
                for (int k = 0; k < 4; k++) {
                    int x = i + d[k][0];
                    int y = j + d[k][1];
                    if (x < 1 || x > n || y < 1 || y > n || g[x][y]) 
                        continue;
                    e[r[i][j]].pb(r[x][y]);
                }

    cout << match() * 2 << '\n';
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