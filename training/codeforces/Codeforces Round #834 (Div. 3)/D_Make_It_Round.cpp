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

ll n, m;
void solve() {
    cin >> n >> m;
    ll a = 0, t = n, b = 0, x = 0, y = 0;
    while (1) {
        if (t % 10 == 0) t /= 10, a++, b++;
        else if (t % 2 == 0) t /= 2, a++;
        else if (t % 5 == 0) t /= 5, b++;
        else break;
    }
    ll res = 1;
    // t = m;
    // while (t) {
    //     if (t >= 10) x++, y++, res *= 10;
    //     t /= 10;
    // }

    if (a > b) {
        int d = a - b;
        while (d > 0 && res * 5 <= m) {
            res *= 5;
            d--;
        }
    } else {
        int d = b - a;
        while (d > 0 && res * 2 <= m) {
            res *= 2;
            d--;
        }
    }
    while (res * 10 <= m) {
        res *= 10;
    }
    res = (m / res) * res;
    cout << (res * n) << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
