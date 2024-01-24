#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 100010, mod = 1e9 + 7;

ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

ll je[N], nx = 1;
void get(ll x) {
    if (nx >= x) return ;
    for (; nx <= x; nx++) {
        je[nx] = (1ll * je[nx - 1] * nx) % mod;
    }
}
void add(ll &x, ll y) {
    x = (x * y) % mod;
}
int main() {
    int _;
    scanf("%d", &_);
    je[0] = je[1] = 1;
    while (_--) {
        ll n;
        scanf("%lld", &n);
        get(n);
        ll ans = 1;
        add(ans, n+3);
        add(ans, n+2);
        add(ans, n+1);
        add(ans, qmi(n, 3));
        add(ans, qmi(n-1,2));
        add(ans, je[n-2]);
        ans = (ans * qmi(96, mod-2)) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}