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

const int mod = 998244353;
int n;
string s;
void solve() {
    cin >> n;
    cin >> s;
    s = "#" + s;
    vector<ll> dp(n + 1, 0);
    dp[1] = s[1] - '0';
    ll pre = 1 + dp[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = (10 * dp[i - 1] % mod + (pre * (s[i] - '0'))) % mod;
        pre = (pre + dp[i]) % mod;
    }
    cout << dp[n] << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}