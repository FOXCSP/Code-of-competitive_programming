#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

int n;

void solve() {
    cin >> n;
    map<int, ll> mp;
    vector<int> vx;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vx.pb(x);
        mp[x]++;
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    ll ans = mp[vx[0]];
    for (int i = 1; i < SZ(vx); i++) {
        if (vx[i] == vx[i - 1] + 1)
            ans += max(0ll, mp[vx[i]] - mp[vx[i - 1]]);
        else
            ans += mp[vx[i]];
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
