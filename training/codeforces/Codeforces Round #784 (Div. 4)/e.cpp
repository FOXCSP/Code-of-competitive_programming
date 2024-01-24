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
    map<string, int> mp;
    vector<string> s;
    map<char, int> p, q;
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        s.pb(x);
    }
    ll ans = 0;
    for (int i = SZ(s) - 1; i >= 0; i--) {
        int pp = p[s[i][0]], qq = q[s[i][1]];
        int x = mp[s[i]];
        ans += (pp - x) + (qq - x);
        mp[s[i]]++;
        p[s[i][0]]++;
        q[s[i][1]]++;
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
