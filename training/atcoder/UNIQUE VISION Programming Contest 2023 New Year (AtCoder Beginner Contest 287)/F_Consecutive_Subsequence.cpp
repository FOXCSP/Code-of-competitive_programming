#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define pb push_back
#define rp (p<<1|1)
#define lp (p<<1)
#define endl '\n'
#define fi first
#define se second
// #define int long long

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 200010;
int n, dp[N];
map<int, vector<int>> pos;
void solve() {
    cin >> n;
    vector<int> a;
    a.pb(0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.pb(x);
        pos[x].pb(i);
        dp[i] = 1;
    }
    int ans = 0, cur, curi;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (pos[x - 1].size() == 0) continue;
        int p = lower_bound(pos[x - 1].begin(), pos[x - 1].end(), i) - pos[x - 1].begin();
        if (p == pos[x - 1].size()) p--;
        if (p > 0 && pos[x - 1][p] > i) p--;
        p = pos[x - 1][p];
        if (p > i) dp[i] = 1;
        else dp[i] = dp[p] + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
            cur = a[i];
            curi = i;
        }
    }
    vector<int> res;
    res.pb(curi);
    while (int(res.size()) < ans) {
        int x = a[res.back()];
        int p = lower_bound(pos[x - 1].begin(), pos[x - 1].end(), res.back()) - pos[x - 1].begin();
        if (pos[x - 1][p] > res.back()) p--;
        if (p < 0 || p >= pos[x - 1].size()) cout << "error\n";
        res.pb(pos[x - 1][p]);
    }
    cout << ans << '\n';
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " \n"[i == 0];
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}