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

vec<int> e[2010];
int col[2010];
void solve(int CaseT) {
    int n, m;
    cin >> n >> m;
    vec<P(int)> eg;
    for (int i = 1; i <= n; i++)
        col[i] = 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int u, d;
        cin >> u >> d;
        eg.pb({u, d});
        queue<P(int)> que;
        vec<bool> vis(n+1, 0);
        vis[u] = 1;
        que.push({u, 0});
        while (!que.empty()) {
            auto t = que.front(); que.pop();
            if (t.se < d)
                col[t.fi] = 0;
            for (auto v : e[t.fi]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    if (t.se + 1 <= d) 
                        que.push({v, t.se + 1});
                }
            }
        }
    }

    for (auto [u, d] : eg) {
        queue<P(int)> que;
        vec<bool> vis(n+1, 0);
        que.push({u, 0});
        vis[u] = 1;
        int cnt = 0;
        while (!que.empty()) {
            auto t = que.front(); que.pop();
            if (t.se < d && col[t.fi] == 1) {
                cout << "No\n";
                return ;
            }

            if (t.se == d && col[t.fi] == 1)
                cnt++;
            for (auto v : e[t.fi]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    if (t.se + 1 <= d) 
                        que.push({v, t.se + 1});
                }
            }
        }
        if (!cnt) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
        cout << col[i];
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