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
map<int, int> f, mxpos, mnpos;
int n;
void solve() {
    cin >> n;
    vector<int> vx;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vx.pb(x);
        if (f[x] == 0) mnpos[x] = i;
        f[x] = 1;
        mxpos[x] = i;
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    int ans = 0, res;
    for (auto x : vx) {
        if (f[x - 1] && mnpos[x - 1] < mxpos[x]) {
            f[x] += f[x - 1];
        }
        if (ans < f[x]) {
            ans = f[x];
            res = x;
        }
    }
    cout << ans << '\n';
    for (int i = res - ans + 1; i <= res; i++) {
        cout << pos[i] << " \n"[i == res];
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
