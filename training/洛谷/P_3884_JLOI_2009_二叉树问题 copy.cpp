#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 110, M = N * 2;
int n, m;
int h[N], w[M], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int depth[N], fa[N][16];
int q[N];
void bfs(int root) {
    memset(depth, 0x3f, sizeof depth);
    depth[root] = 1, depth[0] = 0; // 哨兵
    int hh = 0, tt = -1;
    q[ ++ tt] = root;
    while(hh <= tt) {
        int t = q[hh ++];
        for(int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if(depth[j] > depth[t] + 1) {
                depth[j] = depth[t] + 1;
                q[++ tt] = j;
                fa[j][0] = t;
                for(int k = 1;k <= 15;k ++) {
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b) {
    int ans = 0;
    bool f = 1;
    if(depth[a] < depth[b]) swap(a, b), f = 0;
    for(int k = 15; k >= 0; k --)
        if(depth[fa[a][k]] >= depth[b]) {
            if(!f) ans += (depth[a] - depth[fa[a][k]]);
            else ans += (depth[a] - depth[fa[a][k]]) * 2;
            a = fa[a][k];
        }
    if(a == b) return ans;
    ans += 3;
    for(int k = 15; k >= 0; k --)
        if(fa[a][k] != fa[b][k])
        {
            int d = depth[a] - depth[fa[a][k]];
            a = fa[a][k];
            b = fa[b][k];
            ans += 3 * d;
        }
    return ans;
}

void solve() {
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1;i < n; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(a, b);
    }
    bfs(1);
    int x, y;
    cin >> x >> y;
    umap mp;
    vector<int> a;
    a.resize(n+1, 0);
    cout << *max_element(depth + 1, depth + n + 1) << "\n";
    for(int i = 1;i <= n; i ++) a[depth[i]] ++;
    cout << *max_element(a.begin(), a.end()) << "\n";
    cout << lca(x, y) << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
