#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 110, mod = 1000000007;
int f[N][N], g[N][N], n, m, k;

void solve() {
    cin >> n >> m >> k;
    for(int i = 1;i <= n; i ++)
        for(int j = 1; j <= m;j ++)
            cin >> g[i][j];
    f[1][1] = 1;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            for(int k = i + 1; k <= n;k ++)
                for(int t = j + 1; t <= m; t ++)
                    if(g[k][t] != g[i][j])
                        f[k][t] = (f[k][t] + f[i][j]) % mod;
    cout << f[n][m];
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
