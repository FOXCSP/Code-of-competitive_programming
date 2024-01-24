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
    cin >> n >> m;
    vector<string> s;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        s.pb(str);
    }
    int res = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int ans = 0;
            for (int k = 0; k < m; k++) {
                // if (s[i][k] == s[j][k]) continue;
                ans += abs(s[i][k] - s[j][k]);
            }
            res = min(res, ans);
        }
    }
    cout << res << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
