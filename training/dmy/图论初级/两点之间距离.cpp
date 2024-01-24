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
vec<int> e[N];
int d[N];

int bfs(int u, int v) {
    queue<P(int)> que;
    que.push({u, 0});
    memset(d, 0x3f, sizeof(d));
    while (!que.empty()) {
        P(int) t = que.front();
        que.pop();
        for (auto v : e[t.fi]) {
            if (d[v] > t.se + 1) {
                d[v] = t.se + 1;
                que.push({v, t.se + 1});
            }
        }
    }
    return d[v];
}

void solve(int CaseT) {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    for (; k--; ) {
        int u, v;
        cin >> u >> v;
        int dist = bfs(u, v);
        if (dist == 0x3f3f3f3f) cout << "-1\n";
        else cout << dist << '\n';
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