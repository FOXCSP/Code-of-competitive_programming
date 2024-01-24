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

const int N = 200010;
int n;
int c[N];
void modify(int x, int y) {
    for (; x <= n; x += x & -x) c[x] += y;
}
int query(int x) {
    int s = 0;
    for (; x; x -= x & -x) s += c[x];
    return s;
}
void solve() {
    cin >> n;
    vector<int> a(n + 1, 0), f(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], c[i] = 0;
    for (int i = n; i >= 1; i--) {
        f[i] = query(a[i]);
        modify(a[i], 1);
    }
    ll ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     cout << f[i] << " \n"[i == n];
    // }
    for (int i = 1; i <= n; i++) ans += f[i];
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
