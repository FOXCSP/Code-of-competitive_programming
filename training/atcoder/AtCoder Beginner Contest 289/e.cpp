#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 2010;
int n, m;
vector<int> e[N];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) e[i].clear();
    vector<int> c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    queue<array<int, 3>> que;
    que.push({1, n, 0});
    while (que.size()) {
        auto [u, v, d] = que.front(); que.pop();
        if (dp[u][v] != -1) continue;
        dp[u][v] = d;
        for (auto a:e[u]) {
            for (auto b:e[v]) {
                if (c[a] != c[b]) que.push({a, b, d + 1});
            }
        }
    }
    cout << dp[n][1] << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
