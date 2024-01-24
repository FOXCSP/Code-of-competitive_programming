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
    ll a = 1, b = 0;
    int now = 1, id = 2, k = 0, cnt = 0;
    while (1) {
        if (now + id <= n) {
            now += id;
            if (!k) b += id;
            else a += id;
        } else {
            if (!k) b += (n - now);
            else a += (n - now);
            break;
        }
        cnt++;
        if (cnt % 2 == 0) k ^= 1;
        id++; 
    }
    cout << a << " " << b << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
