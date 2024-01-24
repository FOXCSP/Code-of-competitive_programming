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

const int N = 100100;
int n, m;
int dep[N], low[N], idx, cnt, ins[N], dfn[N];
stack<int> stk;
vec<int> e[N], scc[N];
void dfs(int u) {
    stk.push(u);
    dfn[u] = low[u] = ++idx; 
    ins[u] = 1;
    for (auto v : e[u]) {
        if (!dfn[v]) dfs(v);
        if (ins[v]) low[u] = min(low[u], low[v]);
    }
    if (dfn[u] == low[u]) {
        ++cnt;
        while (1) {
            int v = stk.top();
            stk.pop();
            ins[v] = 0;
            scc[cnt].pb(v);
            if (u == v) break;
        }
        sort(all(scc[cnt]));
    }
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i);
    }
    sort(scc+1, scc+cnt+1);
    for (int i = 1; i <= cnt; i++) {
        for (auto v : scc[i]) {
            cout << v << " ";
        }
        cout << '\n';
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