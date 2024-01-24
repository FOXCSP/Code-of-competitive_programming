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

const int N = 20010;
int n, m, k;
vec<P(int)> e[N];
int dist[N];

void solve(int CaseT) {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].pb({v, w});
        e[v].pb({u, w}); 
    }
    for (; k--; ) {
        int u, v;
        cin >> u >> v;
        deque<P(int)> que;
        que.push_back({u, 0});
        memset(dist, 0x3f, sizeof dist);
        dist[u] = 0;
        while (!que.empty()) {
            auto [u, d] = que.front();
            que.pop_front();
            for (auto [v, w] : e[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    if (w) que.push_back({v, dist[v]}); 
                    else que.push_front({v, dist[v]});
                }
            }
        }
        if (dist[v] == 0x3f3f3f3f) dist[v] = -1;
        cout << dist[v] << '\n';
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