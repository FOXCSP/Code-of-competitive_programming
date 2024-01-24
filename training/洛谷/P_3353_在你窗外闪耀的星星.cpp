#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010;
int a[N], s[N], n, m;
vector<int> id;
void solve() {
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        int x, y;
        cin >> x >> y;
        a[x] = y;
        id.push_back(x);
    }
    for(int i = 1;i <= N; i ++) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for(auto i : id) {
        int sum = s[i] - s[max(0, i - m)];
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
