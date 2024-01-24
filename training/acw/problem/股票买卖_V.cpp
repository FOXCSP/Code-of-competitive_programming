#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010;
int f[N][4];
int n, w[N];

void solve() {
    cin >> n;
    for(int i = 1;i <= n; i ++) cin >> w[i];
    memset(f, 0xcf, sizeof f);
    for(int i = 0;i <= n; i ++) f[i][2] = 0;
    for(int i = 1;i <= n; i ++) {
        f[i][1] = f[i - 1][0] + w[i];
        f[i][2] = max(f[i - 1][2], f[i - 1][1]);
        f[i][0] = max(f[i - 1][2] - w[i], f[i - 1][1]);
    }
    int res = 0;
    for(int i = 1;i <= n;i ++) res = max({res, f[i][1], f[i][2]});
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
