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

int n, q;

void solve() {
    cin >> n >> q;
    vector<ll> v;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        v.pb(x);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++) if (i) v[i] += v[i - 1];
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        int p = lower_bound(v.begin(), v.end(), x) - v.begin();
        if (p + 1 <= n) cout << p + 1 << '\n';
        else cout << "-1\n";
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
