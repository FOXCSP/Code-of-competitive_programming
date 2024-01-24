#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010;
int f[N][110][2];
int n, w[N], k;

void solve() {
    cin >> n >> k;
    memset(f, 0xcf, sizeof f);
    for(int i = 0;i <= n; i ++) f[i][0][0] = 0;
    for(int i = 1;i <= n; i ++) cin >> w[i];
    for(int i = 1;i <= n; i ++) {
        for(int j = 1;j <= k; j ++) {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
        }
    }
    int res = 0;
    for(int i = 1 ;i <= k;i ++)
        res = max(res, f[n][i][0]);
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
