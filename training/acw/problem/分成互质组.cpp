#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

int gcd(int x, int y) {
    return y ? gcd(y, x%y) : x;
}
const int N = 10;
int n, a[N];
vector<int> g[N];
int len, ans = N;

bool check(int u, int c) {
    for(int i = 0; i < g[c].size(); i ++)
        if(gcd(g[c][i], u) > 1) return false;
    return true;
}

void dfs(int u) {
    if(u == n) {
        ans = min(ans, len);
        return ;
    }
    for(int i = 0; i < len; i ++) {
        if(check(a[u], i)) {
            g[i].push_back(a[u]);
            dfs(u + 1);
            g[i].pop_back();
        }
    }
    g[len ++].push_back(a[u]);
    dfs(u + 1);
    g[-- len].pop_back();
}

void solve() {
    cin >> n;
    for(int i = 0;i < n;i ++) cin >> a[i];
    dfs(0);
    cout << ans << '\n'; 
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
