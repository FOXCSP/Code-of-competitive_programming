#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 4e5 + 10;

int a[N], s[N];
int n, m;

void solve() {
    cin >> n >> m;
    for(int i = 1;i <= n; i ++ ) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int t = 0;
    for(int i = 1;i <= m;i ++) t += i * a[i];
    int ans = t;
    for(int i = m; i < n;i ++) {
        t = t - (s[i] - s[i - m] - m * a[i + 1]);
        ans = max(ans, t);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
