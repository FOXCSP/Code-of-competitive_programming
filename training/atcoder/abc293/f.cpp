#include <bits/stdc++.h>
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

int n, m, len;
const int N = 200010;

bool cmp(array<int, 3> a, array<int, 3> b) {
    int x = a[0]/len;
    int y = b[0]/len;
    if (x != y) return x < y;
    else return a[1] < b[1];
}

void solve() {
    cin >> n >> m;
    vec<int> a(n+1,0);
    vec<int> cnt(N, 0);
    vec<array<int, 3>> evt;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        evt.pb({l, r, i});
    }
    len = max(1ll, (ll)sqrtl(1.0 * n * n / m));
    sort(all(evt), cmp);
    
    ll ans = 0;
    int l = 0, r= 0;
    ll res[N];

    auto add = [&](int p) {
        cnt[a[p]]++;
        ll x = cnt[a[p]];
        if (x >= 3) ans += 1ll*(x-1)*(x-2)/2;
    };

    auto sub = [&](int p) {
        cnt[a[p]]--;
        int x = cnt[a[p]];
        if (x + 1 >= 3) ans -= 1ll*x*(x-1)/2;
    };


    for (auto x : evt) {
        while (r < x[1]) r++, add(r);
        while (r > x[1]) sub(r), r--;
        while (l < x[0]) sub(l), l++;
        while (l > x[0]) l--, add(l);
        res[x[2]] = ans;
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    for (int i = 1; i <= _; i++) {
        solve();
    }
    return 0;
}