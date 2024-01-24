#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 1000010, M = N * 2;

int n, m, sz[N];
int h[N], e[M], ne[M], idx;
void add(int a ,int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u, int fa) {
    int res = 1;
    for(int i = h[u]; i != -1; i = ne[i])
        if(fa != e[i]) res += dfs(e[i], u);
    return sz[u] = res;
}

bool check(int u) {
    int p = 0;
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        int t = sz[j] > sz[u] ? n - sz[u] : sz[j];
        if(!p) p = t;
        else if(p != t) return false;
    }
    return true;
}

void solve() {
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    // for(int i = 1;i <= n; i ++ ) {
    //     cout << sz[i] << " \n"[i == n];
    // }
    for(int i = 1;i <= n; i ++ ) {
        if(check(i)) cout << i << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
