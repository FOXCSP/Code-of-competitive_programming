#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 20;
int a[N], n, w;
int len, ans = N;
int g[N];
void dfs(int u) {
    if(len > ans) return ;
    if(u == n) {
        ans = min(ans, len);
        return ;
    }
    for(int i = 0;i < len; i ++) {
        if(g[i] + a[u] <= w) {
            g[i] += a[u];
            dfs(u + 1);
            g[i] -= a[u];
        }
    }
    g[len ++] = a[u];
    dfs(u + 1);
    g[-- len] = 0;
}

void solve() {
    cin >> n >> w;
    for(int i = 0;i < n;i ++) cin >> a[i];
    sort(a, a + n, greater<int>());
    dfs(0);
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}