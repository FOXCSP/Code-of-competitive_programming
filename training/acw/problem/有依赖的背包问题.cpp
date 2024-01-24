#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 110;
int h[N], ne[N], e[N], idx;
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int n, m, w[N], v[N];
int f[N][N];
void dfs(int u) {
    for(int i = h[u]; i != -1; i = ne[i]) {
        int son = e[i];
        dfs(e[i]);
        for(int j = m - v[u]; j >= 0; j --)
            for(int k = 0;k <= j; k ++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
    }
    for(int i = m;i >= v[u];i --) f[u][i] = f[u][i - v[u]] + w[u];
    for(int i = 0;i < v[u];i ++) f[u][i] = 0;
}


void solve() {
    cin >> n >> m;
    int root;
    memset(h, -1, sizeof h);
    for(int i = 1;i <= n;i ++) {
        int a, b, p;
        cin >> a >> b >> p;
        if(p == -1) root = i;
        else add(p, i);
        v[i] = a, w[i] = b;
    }
    dfs(root);
    cout << f[root][m] << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
