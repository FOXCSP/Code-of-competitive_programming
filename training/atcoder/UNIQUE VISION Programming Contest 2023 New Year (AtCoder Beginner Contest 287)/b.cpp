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

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    int ans = 0;
    vector<string> s;
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        s.pb(x);
    }
    for (int i = 1; i <= m; i++) {
        string x;
        cin >> x;
        mp[x]++;
    }
    for (auto x : s) {
        string t = x.substr(3, 3);
        if (mp[t]) ans++;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
