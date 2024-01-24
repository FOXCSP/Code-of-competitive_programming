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
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<P(int)> a;
    int ans = 0, l, r;
    auto modify = [&]() {
        if (ans < SZ(a)) {
            l = a[0].fi;
            r = a.back().fi;
            ans = SZ(a);
        }
        a.clear();
    };
    for (auto [x, y] : mp) {
        // cout << x << " " << y << "\n";
        if (SZ(a) == 0) {if (y >= k) a.pb({x, y}); else modify();}
        else if (x == a.back().fi + 1) {if (y >= k) a.pb({x, y}); else modify();}
        else {modify(); if (y >= k) a.pb({x, y});}
    }
    if (ans < SZ(a)) {
        l = a[0].fi;
        r = a.back().fi;
        ans = SZ(a);
    } 
    if (ans) cout << l << " " << r << '\n';
    else cout << "-1\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
