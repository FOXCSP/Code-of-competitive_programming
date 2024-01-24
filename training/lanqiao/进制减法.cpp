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
using ll = long long;
typedef double db;
typedef long double ldb;
// 开根号请使用    sqrtl 谢谢  sb sqrt 已死

// -- head--
const int N = 2010;
const int mod = 1e9+7;
void solve(int CaseT) {
    vec<int> a, b;
    int n, ma, mb;
    cin >> n;
    cin >> ma;
    for (int i = 0; i < ma; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }
    cin>>mb;
    for (int i = 0; i < mb; i++) {
        int x;
        cin >> x;
        b.pb(x);
    }

    reverse(all(a));
    reverse(all(b));


    vec<int> c;
    vec<int> jz;
    for (int i = 0; i < SZ(a) || i < SZ(b); i++) {
        int t = 0;
        if (i < SZ(a)) t += a[i];
        if (i < SZ(b)) t -= b[i];
        c.pb(t);
        jz.pb(max(2ll, max(a[i], b[i]) + 1));
    }

    for (int i = 0; i < SZ(c); i++) {
        if (c[i] < 0) c[i] = (jz[i]+c[i]), c[i+1]--;
    }



    ll ans=0;
    ll p = 1;
    for (int i = 0; i < SZ(c); i++) {
        ans = (ans+c[i] * p) % mod;
        p = (p*jz[i])%mod;
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