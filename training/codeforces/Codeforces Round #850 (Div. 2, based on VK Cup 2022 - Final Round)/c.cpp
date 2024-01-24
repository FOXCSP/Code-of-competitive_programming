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
    vector<int> a;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll ans = 0, x = 1;
    while (SZ(a)) {
        int t = a.back(); a.pop_back();
        if (t < x) continue;
        else ans += t - x, x++;
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
