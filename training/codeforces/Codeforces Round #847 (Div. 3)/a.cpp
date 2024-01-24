#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

void solve() {
    string s = "314159265358979323846264338327";
    string t;
    cin >> t;
    int cnt = 0;
    for (int i = 0; i < SZ(t); i++) {
        if (s[i] != t[i]) break;
        cnt++; 
    }
    cout << cnt << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
