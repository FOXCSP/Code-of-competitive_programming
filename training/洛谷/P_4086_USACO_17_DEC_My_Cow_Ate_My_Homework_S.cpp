#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010;
int f[N][18], a[N], n, m;
void st() {
    memset(f, 0x3f, sizeof f);
    for(int i = 1;i <= n;i ++) f[i][0] = a[i];
    int t = log2(n) + 1;
    for(int j = 1; j < t; j ++)
        for(int i = 1; i <= n - (1 << j) + 1; i ++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
    int k = log2(r - l + 1);
    return min(f[l][k], f[r - (1<<k) + 1][k]);
}
int s[N];
void solve() {
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    st();
    vector<int> ans;
    double m = -1.0;
    for(int k = 1;k <= n - 2;k ++) {
        double d = 1.0 * (s[n] - s[k] - query(n - k + 1, n)) / (1.0 * (n - k - 1));
        if(d >= m) {
            if(d > m) m = d, ans.clear(), ans.push_back(k);
            else ans.push_back(k);
        }
    }
    for(auto c : ans) {
        cout << c << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
