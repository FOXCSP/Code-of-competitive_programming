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

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    bool f = false;
    for (auto c : s) {
        if (c == 'L') y -= 1;
        if (c == 'R') y += 1;
        if (c == 'U') x += 1;
        if (c == 'D') x -= 1;
        if (x == 1 && y == 1) f = 1;
    }
    puts(f ? "YES":"NO");
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
