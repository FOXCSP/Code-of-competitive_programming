#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1010, mod = 1e9+7;
int f[N], g[N];
int n, m;

void solve() {
    cin >> n >> m;
    memset(f, 0xcf, sizeof f);
    f[0] = 0;
    g[0] = 1;
    for(int i = 1;i <= n;i ++) {
        int v, w;
        cin >> v >> w;
        for(int j = m ; j >= v; j --) {
            int maxv = max(f[j], f[j - v] + w);
            int cnt = 0;
            if(f[j] == maxv) cnt = (cnt + g[j]) % mod;
            if(f[j - v] + w == maxv) cnt = (cnt + g[j - v]) % mod;
            f[j] = maxv;
            g[j] = cnt;
        }
    }
    // find the max ans
    int res = -1e9;
    for(int i = 0;i <= m; i ++ ) res = max(res, f[i]);
    
    // check the count of the ans
    int cnt = 0;
    for(int i = 0;i <= m; i ++) 
        if(res == f[i])
            cnt = (cnt + g[i]) % mod;
    // cout << res << endl;
    cout << cnt << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
