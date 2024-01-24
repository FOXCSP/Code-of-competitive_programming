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
vec<P(int)> e[N];
int dist[N], vis[N];

int dijkstra(int s, int t) {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[s] = 0;
    priority_queue<P(int), vec<P(int)>, greater<P(int)> > que;
    que.push({0, s});
    while (!que.empty()) {
        auto [d, u] = que.top(); que.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : e[u]) {
            if (!vis[v]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    que.push({dist[v], v});
                }
            }
        }
    }
    if (dist[t] == 0x3f3f3f3f) dist[t] = -1;
    return dist[t];
}

void solve(int CaseT) {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].pb({v, w});
    }
    for (; k--; ) {
        int u, v;
        cin >> u >> v;
        cout << dijkstra(u, v) << '\n';
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