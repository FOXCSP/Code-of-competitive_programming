#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 1010;
int a[N][N], n, s[N][N];

void solve() {
    cin >> n;
    int p = 0, q = 0;
    for(int i = 1;i <= n; i++) {
        int x, y;
        cin >> x >> y;
        p = max(p, x);
        q = max(q, y);
        a[x][y] = 1;
    }
    for(int i = 1;i <= p;i ++)
        for(int j = 1;j <= q; j ++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

    int ans = 1e9;
    for(int i = 2;i <= p;i += 2) {
        for(int j = 2;j <= q;j += 2) {
            int s1 = s[i - 1][j - 1];
            int s2 = s[i - 1][q] + s[i - 1][j - 1] - s[i - 1][j];
            int s3 = s[p][j - 1] + s[i - 1][j - 1] - s[i][j - 1];
            int s4 = s[p][q] - s[i][q] - s[p][j] + s[i][j];
            ans = min(max({s1, s2, s3, s4}), ans);
            cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
