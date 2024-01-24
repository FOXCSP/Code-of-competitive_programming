#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010, M = 200010;
int a[N], sz[N], n, k;
int h[N], ne[M], e[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u) {
    int cnt = 1;
    for(int i = h[u]; i != -1; i = ne[i])
        cnt += dfs(e[i]);
    return sz[u] = cnt;
}

void solve() {
    cin >> n >> k;
    memset(h, -1, sizeof h);
    memset(sz, 0, sizeof sz);
    for(int i = 1;i < n; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    dfs(1);
    int cnt = 0;
    for(int i = 1;i <= n;i ++) {
        if(sz[i] % k == 0) {
            cnt ++;
        }
        if(cnt > n/k) {
            break;
        }
        cout << sz[i] << " \n"[i == n];
    }
    if(cnt == k) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
