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

const int N = 100010;
int n, m, k;
vec<P(int)> e[N], re[N];
int dist1[N], vis[N];
int dist2[N];

void dijkstra1(int s) {
    memset(dist1, 0x3f, sizeof dist1);
    memset(vis, 0, sizeof vis);
    dist1[s] = 0;
    priority_queue<P(int), vec<P(int)>, greater<P(int)> > que;
    que.push({0, s});
    while (!que.empty()) {
        auto [d, u] = que.top(); que.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : e[u]) {
            if (!vis[v]) {
                if (dist1[v] > d + w) {
                    dist1[v] = d + w;
                    que.push({dist1[v], v});
                }
            }
        }
    }
}

void dijkstra2(int s) {
    memset(dist2, 0x3f, sizeof dist2);
    memset(vis, 0, sizeof vis);
    dist2[s] = 0;
    priority_queue<P(int), vec<P(int)>, greater<P(int)> > que;
    que.push({0, s});
    while (!que.empty()) {
        auto [d, u] = que.top(); que.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : re[u]) {
            if (!vis[v]) {
                if (dist2[v] > d + w) {
                    dist2[v] = d + w;
                    que.push({dist2[v], v});
                }
            }
        }
    }
}

void solve(int CaseT) {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].pb({v, w});
        re[v].pb({u, w});
    }
    dijkstra1(k);
    dijkstra2(k);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dist1[i] + dist2[i]);
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