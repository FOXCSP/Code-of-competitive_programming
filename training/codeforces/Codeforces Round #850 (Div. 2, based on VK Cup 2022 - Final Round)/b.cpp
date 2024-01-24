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

int n, w ,h;

void solve() {
    cin >> n >> w >> h;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int l = -1e9, r = 1e9;
    for (int i = 1; i <= n; i++) {
        l = max(l, a[i] - w - b[i] + h);
        r = min(r, a[i] + w - b[i] - h);
    }
    if (l <= r) cout << "YES\n";
    else cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
