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

int n, s, r;

void solve() {
    cin >> n >> s >> r;
    int x = s - r;
    int t;
    if (x == 1) {
        t = 0;
    } else {
        t = (s - n) / (x - 1);
    }
    int res = s - (n - t) - (x * t);
    for (int i = 1; i <= t; i++) cout << x << " ";
    for (int i = 1; i <= n - t; i++) {
       if (i != n - t) cout << "1 ";
       else cout << res + 1 << " ";
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
