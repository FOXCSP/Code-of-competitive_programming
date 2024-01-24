#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}



void solve() {
    ll x;
    cin >> x;
    if (x & 1) cout << "-1\n";
    else {
        ll t = x / 2;
        if ((t ^ (1ll * t * 3)) != 1ll * 2 * t)
            cout << "-1\n";
        else
            cout << t << " " << t * 3 << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    // for (int a = 1; a <= 5000; a++) {
    //     for (int b = a; b <= 5000; b++) {
    //         if ((a + b)/2 == (a ^ b)) {
    //             if (a + b > 340 && a + b < 512) {
    //                 cout << a << " " << b << '\n';
    //             }
    //             if (a * 3 == b) 
    //                 cout << a << " " << b << " " << (a ^ b) << " " << (a + b) << '\n';
    //         }
    //     }
    // }
    // cout << (1 << 27) << '\n';
    return 0;
}
