#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
#define pb push_back
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 200010;
vector<int> e[N];
int n, m;
bool st[N], flg;
void dfs(int u, int fa) {
    st[u] = 1;
    if (SZ(e[u]) != 2) flg = false;
    for (auto v : e[u]) {
        if (v == fa || st[v]) continue;
        dfs(v, u);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i]) continue;
        flg = true;
        dfs(i, 0);
        ans += flg;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
