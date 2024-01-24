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
    vector<P(int)> card;
    int id = 1, now = 0;
    while (1) {
        int p = (id * (id - 1) / 2) + 1;
        if (now + id > n) id = n - now;
        now += id;
        if (id & 1) {
            int x = id / 2 + (p & 1);
            int y = id / 2 + !(p & 1);
            card.pb({x, y});
        } else {
            card.pb({id/2, id/2});
        }
        id++;
        if (now == n) break;
    }
    P(int) a = {1, 0}, b = {0, 0};
    int m = SZ(card), k = 0;
    reverse(card.begin(), card.end());
    card.pop_back();
    while (SZ(card)) {
        P(int) x = card.back(); card.pop_back();
        P(int) y = {0, 0};
        if (SZ(card)) y = card.back(), card.pop_back();
        if (k) {
            a.fi += x.fi + y.fi;
            a.se += x.se + y.se;
        } else {
            b.fi += x.fi + y.fi;
            b.se += x.se + y.se;
        }
        k ^= 1;
    }
    cout << a.fi << " " << a.se << " " << b.fi << " " << b.se << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
