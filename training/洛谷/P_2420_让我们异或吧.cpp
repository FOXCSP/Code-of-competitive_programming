#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010, M = N * 2;
int h[N], w[M], ne[M], e[M], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int oxr[N];
bool st[N];
void dfs(int u, int o) {
    st[u] = 1;
    oxr[u] = o;
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if(st[j]) continue;
        dfs(j, o ^ w[i]);
    }
}

int n;
void solve() {
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1;i < n; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, 0);
    int q; cin >> q;
    while( q --) {
        int x, y;
        cin >> x >> y;
        cout << (oxr[x] ^ oxr[y]) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
