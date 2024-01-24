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

int n, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n + 1, 0), cnt(31, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j <= 30; j++) {
            if (a[i] >> j & 1) cnt[j]++;
        }
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (k >= n - cnt[i]) {
            k -= n - cnt[i];
            ans += 1 << i;
        }
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
