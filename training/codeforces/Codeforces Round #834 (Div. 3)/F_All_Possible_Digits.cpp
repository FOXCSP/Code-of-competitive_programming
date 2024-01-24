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

int n, p;
void solve() {
    cin >> n >> p;
    int ans = 0;
    vector<int> a(n + 1, 0);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;
    int t = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == p - 1) continue;
        else {t = a[i]; break;}
    }
    int y = a[n];
    int mx1 = -1, mx2 = -1;
    for (int i = y; i >= 0; i--) {
        if (mp[i] == 0) {
            if (mx1 == -1) mx1 = i;
            else {
                mx2 = i;
                break;
            }
        }
    }
    if (mx1 == -1) {
        int mx = p - 1;
        while (mp[mx]) mx--;
        if (mx > y) ans = mx - y; 
    } else {
        ans = p - y;
        // cout << mx1 << " " << mx2 << '\n';
        if (mx1 == t + 1) {if (mx2 != -1) ans += mx2;}
        else ans += mx1;
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
