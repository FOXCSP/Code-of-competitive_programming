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

int l, r, x, a, b;

void solve() {
    cin >> l >> r >> x >> a >> b;
    int lb = b - x, rb = b + x;
    if (a == b) {
        cout << "0\n";
    } else if (lb < l && rb > r) {
        cout << "-1\n";
    } else if (a - x < l && a + x > r) {
        cout << "-1\n";
    } else if (a <= lb || a >= rb) {
        cout << "1\n";
    } else if ((a - l >= x && b - l >= x) || (r - a >= x && r - b >= x)) {
        cout << "2\n";
    } else {
        cout << "3\n";
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
