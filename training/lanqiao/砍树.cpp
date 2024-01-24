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

ll random(ll x) {
    return (1ll * rand() * rand()) % x + 1;
}

const int N = 100010;
const ll mod = 998244353;
vec<int> e[N];
ll val[N];
int fa[N], n, m;
ll res = 0, flg = 0;
void dfs(int u, int f) {
    fa[u] = f;
    for (auto v : e[u]) {
        if (v == f) continue;
        dfs(v, u);
        val[u] = (val[u] + val[v]) % mod;
    }
}

void solve(int CaseT) {
    cin >> n >> m;
    vec<array<int, 3>> eg;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        eg.pb({u, v, i});
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ll h = random(mod);
        val[u] = (val[u] + h) % mod;
        val[v] = (val[v] + h) % mod;
        flg = (flg + h) % mod;
    }

    dfs(1, 0);

    reverse(all(eg));

    for (auto x : eg) {
        int u = x[0];
        int v = x[1];
        int i = x[2];
        if (fa[v] != u) swap(u, v);
        if (val[v] == flg) {
            cout << i << '\n';
            return ;
        }
    }
    cout << "-1\n";
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