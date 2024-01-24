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
    int l = 0, r = n - 1, cnt = 0;
    while (l < r) {
        if (abs(s[l] - s[r]) == 1) l++, r--, cnt += 2;
        else break;
    }
    cout << n - cnt << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
