#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

int n;

void solve() {
    cin >> n;
    vector<int> a(n + 1, 0), p(n + 1, 0);
    map<int, vector<P(int)>> mp;
    int tot = 1, all = 0;
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
        if (a[i] == 0) tot++;
        else {
            mp[tot].pb({a[i], i});
            if (a[i] < 0) p[tot]++;
        }
    }

    P(int) ans;
    int val = -1e9;
    // cout << tot << " size\n";
    for (int i = 1; i <= tot; i++) {
        all += SZ(mp[i]);
        if (SZ(mp[i]) == 0) continue;
        int m = SZ(mp[i]);
        if (p[i] & 1) {
            P(int) res;
            int t = 0;
            int mx1 = 0, mx2 = 0, mi1 = mp[i][0].se, mi2 = mp[i].back().se;
            
            while (t < m && mp[i][t].fi > 0) {
                mx1 += (abs(mp[i][t].fi) == 2);
                t++;
                mi1 = mp[i][t].se;
            }
            mx1 += (abs(mp[i][t].fi) == 2);
            
            
            t = m - 1;
            while (t >= 0 && mp[i][t].fi > 0) {
                mx2 += (abs(mp[i][t].fi) == 2);
                t--;
                mi2 = mp[i][t].se;
            }
            mx2 += (abs(mp[i][t].fi) == 2);
            
            if (mx1 < mx2) {
                res = {mi1 + 1, mp[i].back().se};
            } else {
                res = {mp[i][0].se, mi2 - 1};
            }

            int cnt = 0;
            for (int j = 0; j < m; j++) cnt += (abs(mp[i][j].fi) == 2);

            if (cnt - min(mx1, mx2) > val) {
                val = cnt - min(mx1, mx2);
                ans = res;
            }
        } else {
            int res = 0;
            for (int j = 0; j < m; j++) res += (abs(mp[i][j].fi) == 2);
            if (res > val) {
                val = res;
                ans = {mp[i][0].se, mp[i].back().se};
            }
        }
    }
    if (all == 0) {
        cout << n << " " << 0 << '\n';
    } else  cout << ans.fi - 1 << " " << n - ans.se << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
