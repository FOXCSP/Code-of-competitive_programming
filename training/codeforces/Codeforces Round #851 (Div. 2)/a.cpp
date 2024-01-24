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
    vector<int> a(n + 1, 0), f(n + 1,0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 2) f[i]++;
    }
    for (int i = 1; i <= n; i++) {
        f[i] += f[i - 1];
    }
    for (int k = 1; k < n; k++) {
        if (f[k] == f[n] - f[k]) {
            cout << k << '\n';
            return ;
        }
    }
    cout << "-1\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
