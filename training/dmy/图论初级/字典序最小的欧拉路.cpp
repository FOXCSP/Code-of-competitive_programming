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
vec<P(int)> e[N];
int n, m, dig[N];
vec<int> path;
bool vis[N];
void dfs(int u) {
    for (auto [v, id]: e[u]) {
        if (!vis[id]) {
            vis[id] = 1;
            dfs(v);
            path.pb(v);
        }
    }
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb({v, i});
        e[v].pb({u, i});
        dig[u]++;
        dig[v]++;
    }
    vec<int> bd;
    for (int i = 1; i <= n; i++) {
        sort(all(e[i]));
        if (dig[i] & 1) bd.pb(i);
    }
    if (SZ(bd) == 0) bd.pb(1);
    else {
        sort(all(bd));
        bd.pop_back();
    }
    dfs(bd[0]);
    path.pb(bd[0]);
    for (int i = SZ(path) - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    _ = 1;
    for (int i = 1; i <= _; i++) {
        solve(i);
    }
    return 0;
}