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
vec<int> e[N];
int n, m, dig[N];
void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[v].pb(u);
        dig[u]++;
    }

    // priority_queue<int, vec<int>, greater<int> > que;
    queue<int> que;

    int ans = 0;
    int res[N];
    for (int i = 1; i <= n; i++) 
        if (!dig[i]) {
            que.push(i);
            ans += 100;
            res[i] = 100;
        }

    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto v : e[u])
            if (!(--dig[v])) {
                que.push(v);
                ans += res[u] + 1;
                res[v] = res[u] + 1;
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