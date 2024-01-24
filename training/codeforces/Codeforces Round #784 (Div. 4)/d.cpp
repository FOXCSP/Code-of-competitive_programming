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
string s;

void solve() {
    cin >> n >> s;
    s = "#" + s;
    int a = 0, b = 0;
    bool f = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'W') {
            if (a == 0 && b == 0) continue;
            if (!(a >= 1 && b >= 1)) f = false;
            a = 0; b = 0; 
        } else {
            a += s[i] == 'R';
            b += s[i] == 'B';
        }
    }
    if (a + b > 0) if (!(a >= 1 && b >= 1)) f = false;
    puts(f ? "YES":"NO");
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
