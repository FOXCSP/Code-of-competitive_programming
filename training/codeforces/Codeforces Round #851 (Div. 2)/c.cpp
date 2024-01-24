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

void solve() {
    cin >> n;
    ll x = (3 * n + 3) / 2;
    if ((3 * n + 3) % 2 == 0) {
        cout << "YES\n";
        vector<int> a;
        int p = 1;
        while (p <= n) {
            a.pb(p);
            p+=2;
        }
        p = 2;
        while (p <= n) {
            a.pb(p);
            p+=2;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " " << x - a[i] << "\n";
            x++;
        }
    }
    else cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
