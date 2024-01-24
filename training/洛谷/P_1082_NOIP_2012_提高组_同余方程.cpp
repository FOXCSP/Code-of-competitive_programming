#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll x, y;
void exgcd(ll a, ll b) {
    if(b == 0) {
        x = 1ll;
        y = 0ll;
        return ;
    }
    exgcd(b, a % b);
    ll t = x;
    x = y;
    y = t - a / b * y;
}

int main() {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    exgcd(a, b);
    x = (x % b + b) % b;
    printf("%lld\n", x);
    return 0;
}

/*
ll ul(ll b) {
    ll ans = b;
    for(ll i = 2; i <= b / i; i ++) {
        if(b % i == 0) {
            ans = ans * (i - 1) / i;
            while(b % i == 0) b /= i;
        }
    }
    if(b > 1) ans = (ans * (b - 1)) / b;
    return ans;
}
ll a, b;
ll qmi(ll c, ll k) {
    ll res = 1;
    while(k) {
        if(k & 1) res = res * c % b;
        c = (c * c) % b;
        k >>= 1;
    }
    return res;
}

int main () {
    cin >> a >> b;
    // cout << ul(b) << endl;
    cout << qmi(a, ul(b) - 1) << endl;
    return 0;
}
*/