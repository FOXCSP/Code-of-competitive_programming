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
    string s = to_string(n);
    string a = "", b = "";
    int sum = 0;
    for (int i = 0; i < SZ(s); i++) {
        int v = s[i] - '0';
        int x, y;
        if (sum > 0) {
            x = v/2;
        } else {
            x = (v+1)/2;
        }
        y = v - x;
        a += '0' + x;
        b += '0' + y;
        sum += x - y;
    }
    int p = stoi(a);
    int q = stoi(b);
    cout << p << " " << q << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
