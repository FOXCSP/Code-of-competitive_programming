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



void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < SZ(s); i++) {
        s[i] = (1 - (s[i] - '0')) + '0';
    }
    cout << s << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
