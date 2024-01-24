#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010;

int n, s, ans;
int h[N], w[N], ne[N], e[N], idx, p[N];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool st[N];
void dfs(int u, int d) {
    if(d == s) {
        ans ++;
        return ;
    }
    if(d > s) return ;
    for(int i = h[u]; ~i ; i = ne[i]) {
        int j = e[i];
        dfs(j, d + w[j]);
    }
}


void solve() {
    cin >> n >> s;
    memset(h, -1, sizeof h);
    for(int i = 1;i <= n;i ++ ) cin >> w[i];
    for(int i = 1;i <= n - 1;i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        p[b] = a;  
    }
    for(int i = 1;i <= n;i ++) {
        dfs(i, w[i]);
    }
    
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
