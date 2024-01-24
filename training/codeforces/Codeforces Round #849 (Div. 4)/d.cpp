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
string s;

void solve() {
    cin >> n >> s;
    s = "#" + s;
    vector<int> pre(n + 1, 0), suf(n + 2, 0);
    map<char, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[s[i]]++;
        pre[i] = SZ(mp);
    }
    mp.clear();
    for (int i = n; i >= 1; i--) {
        mp[s[i]]++;
        suf[i] = SZ(mp);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int res = pre[i] + suf[i + 1];
        ans = max(ans, res);
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
