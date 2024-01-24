#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 2010;
int f[N], n, m;
int a[N];
void solve() {
    cin >> n >> m;
    memset(f, 0xcf, sizeof f);
    for(int i = 1;i <= n;i ++) cin >> a[i];
    f[0] = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = m;j >= 1;j --)
            f[j] = max(f[j], f[j - 1] + j * a[i]);
    cout << f[m] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
