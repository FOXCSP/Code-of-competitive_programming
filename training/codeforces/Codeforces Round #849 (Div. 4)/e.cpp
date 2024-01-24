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
    vector<ll> a(n + 1, 0), b;
    ll sum = 0, mn = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] < 0) b.pb(a[i]);
        else mn = min(mn, a[i]);
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    while (SZ(b) > 1) {
        ll t = b.back();
        b.pop_back();
        t += b.back();
        b.pop_back();
        sum += 2 * abs(t);
    }
    if (SZ(b) != 0) {
        ll t = b.back() + mn;
        if (t < 0) sum += 2 * abs(t);
    }
    cout << sum << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
