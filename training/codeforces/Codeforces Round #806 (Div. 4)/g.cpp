#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 100010;
int n;
ll a[N], k, s[N];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll res = s[i] - i * k;
        for (int j = i + 1, x = 1; j <= n; j++, x++) {
            ll t = (a[j] / (1ll << x));
            res += t;
            if (x == 30) break;
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
