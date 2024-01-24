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

vector<string> s;

void solve() {
    string str;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        if (i <= m) s.pb(str);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < m; i++) {
        cout << s[i] << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
