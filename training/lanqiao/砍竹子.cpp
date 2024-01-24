#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--
void solve(int CaseT) {
    int n;
    cin >> n;
    vec<ll> a(n);
    vec<ll> vx;

    ll mx = -1e18;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    ll ans = 0;

    while (mx > 1) {
        vec<ll> g(a);
        ll nmx = -1e18;
        for (int j = 0; j < n; j++) {
            ll res = 0;
            if (j && g[j] == a[j - 1]) {
                g[j] = g[j - 1];
                nmx = max(g[j], nmx);
                continue;
            }
            while (g[j] >= mx && g[j] > 1) {
                g[j] = 1ll*sqrt(g[j]/2+1);
                res++;
            }
            nmx = max(g[j], nmx);
            ans += res;
        }
        a.swap(g);
        mx = nmx;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    // cin >> _;
    for (int i = 1; i <= _; i++) {
        solve(i);
    }
    return 0;
}