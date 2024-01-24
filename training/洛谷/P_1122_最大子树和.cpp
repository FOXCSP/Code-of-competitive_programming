#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 200010;

int h[N], w[N], e[N], ne[N], idx;
int f[N];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa) {
    f[u] = w[u];
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if(j != fa) {
            dfs(j, u);
            if(f[j] > 0) f[u] += f[j];
        }
    }
} 

void solve() {
    int n;
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1;i <= n;i ++) cin >> w[i];
    for(int i = 1;i <= n - 1;i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1, 0);
    int ans = -1e9;
    for(int i = 1;i <= n; i ++) ans = max(ans, f[i]);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
