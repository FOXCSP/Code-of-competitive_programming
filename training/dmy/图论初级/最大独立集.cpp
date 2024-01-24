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

const int N = 1010;
vec<int> e1[N], e2[N];
int n, m;
bool vis[N];
int r[N], n1, n2, to[N];

bool find(int u) {
    vis[u] = 1;
    for (auto v : e2[u]) {
        if (!to[v] || (!vis[to[v]] && find(to[v]))) {
            to[v] = u;
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

int col[1010];
void dfs(int u) {
    if (col[u] == 1) 
        r[u] = ++n1;
    else 
        r[u] = ++n2;
    for (auto v : e1[u]) {
        if (!col[v]) {
            col[v] = 3 - col[u];
            dfs(v);
        }
    }
}

void solve(int CaseT) {
    cin >> n >> m;
    vec<P(int)> eg;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e1[u].pb(v);
        e1[v].pb(u);
        eg.pb({u, v});
    }

    for (int i = 1; i <= n; i++)
        if (!col[i]) {
            col[i] = 1;
            dfs(i);
        }
    
    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) {
            for (auto v : e1[i]) {
                if (col[v] == 2)
                    e2[r[i]].pb(r[v]);
            }
        }
    }

    cout << n - match() << '\n';
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