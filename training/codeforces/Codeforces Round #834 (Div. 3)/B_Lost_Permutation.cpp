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

int m, s;

void solve() {
    cin >> m >> s;
    int now = 0;
    vector<int> b(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    now = 1;
    sort(b.begin(), b.end());
    for (int i = 1; i <= m; i++) {
        if (b[i] == now) now++;
        else if (s >= now) s -= now, now++, i--;
        else {
            cout << "NO\n";
            return ;
        }
    }
    if (s) {
        while (s >= now) s -= now, now++;
        if (s) {
            cout << "NO\n";
            return ;
        } 
    } 
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
