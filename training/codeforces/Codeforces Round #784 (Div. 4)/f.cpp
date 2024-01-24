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
    vector<int> a(n + 1, 0), pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = n + 1;
    int ls = 0, rs = 0, ans = 0;
    while (l < r) {
        if (ls <= rs) {
            if (ls && ls == rs) ans = n - (r - l - 1);
            l++, ls += a[l];
        }
        else r--, rs += a[r];
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
