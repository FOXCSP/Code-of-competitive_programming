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

int n, m;

void solve() {
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    cin >> m;
    vector<int> mp(100010, 0);

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int t; cin >> t;
    vector<int> dp(100010, 0);
    dp[0] = 1;
    for (int i = 0; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + a[j] <= t && mp[i + a[j]] == 0) {
                dp[i + a[j]] |= dp[i];
            }
        }
    }
    puts(dp[t] ? "Yes":"No");
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
