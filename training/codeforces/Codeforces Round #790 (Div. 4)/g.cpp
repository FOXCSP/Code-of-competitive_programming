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

const int N = 4010;
int n, m;
vector<int> e[N];
string s;
int sz[N], szw[N];

void dfs(int u, int f) {
    sz[u] = 1;
    // cout << u << '\n';
    if (s[u] == 'W') szw[u]++;
    for (auto v : e[u]) {
        if (v == f) continue;
        dfs(v, u);
        sz[u] += sz[v];
        szw[u] += szw[v];
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) szw[i] = sz[i] = 0, e[i].clear();
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        e[u].pb(i);
        e[i].pb(u);
    }
    cin >> s;
    s = "#" + s;
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (szw[i] == sz[i] - szw[i]) {
            ans++;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
