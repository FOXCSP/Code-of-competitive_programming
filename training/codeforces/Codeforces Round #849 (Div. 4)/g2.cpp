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

int n, c;

void solve() {
    cin >> n >> c;
    vector<ll> a(n + 1), x(n + 1, 0);
    vector<P(ll)> mn(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
       cin >> a[i];
       mn[i].fi = min(i, n + 1 - i) + a[i];
       x[i] = mn[i].fi;
       mn[i].se = i;
    }
    sort(mn.begin(), mn.end());
    vector<int> pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pos[mn[i].se] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) mn[i].fi += mn[i - 1].fi;
    // for (int i = 1; i <= n; i++) {
    //     cout << mn[i].fi << " " << mn[i].se  << '\n';
    // }
    for (int i = 1; i <= n; i++) {
        int d = a[i] + i - x[i];
        if (c >= a[i] + i) ans = max(ans, 1);
        else continue;
        auto check = [&](int x) {
            ll t = mn[x].fi;
            if (pos[i] <= x) return t + d <= c;
            else return t <= c - (a[i] + i);
        };
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        // if (i == 2) cout << l << '\n';
        if (pos[i] > l) l++;
        ans = max(ans, l);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
