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

int n, m, ans;

void solve() { 
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<ll>> dp(3, vector<ll> (2, 0));
    dp[2][1] = m;
    ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int x = 2; x >= 0; x--)
            for (int y = 1; y >= 0; y--) {
                if (x) dp[x - 1][y] = max(dp[x - 1][y], dp[x][y] * 2);
                if (y) dp[x][y - 1] = max(dp[x][y - 1], dp[x][y] * 3);
                if (dp[x][y] > a[i]) {
                    dp[x][y] += a[i] / 2;
                    ans = i;
                }
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
