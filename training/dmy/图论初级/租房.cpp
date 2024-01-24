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

const int N = 100010, inf = 1 << 30;
int n, m, k;
vec<P(int)> e[N];
int vis[N];
vec<ll> dist1, dist2, dist3;

void dijkstra(int s, vec<ll>& dist) {
    memset(vis, 0, sizeof vis);
    dist[s] = 0;
    priority_queue<P(ll), vec<P(ll)>, greater<P(ll)> > que;
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
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].pb({v, w});
        e[v].pb({u, w});
    }
    int a, b, c;
    cin >> a >> b >> c;

    dist1.resize(n + 1, inf);
    dist2.resize(n + 1, inf);
    dist3.resize(n + 1, inf);

    dijkstra(a, dist1);
    dijkstra(b, dist2);
    dijkstra(c, dist3);
    ll ans = 1 << 30;
    for (int i = 1; i <= n; i++) {
        if (ans > dist1[i] + dist2[i] + dist3[i]) {
            ans = dist1[i] + dist2[i] + dist3[i];
        }
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