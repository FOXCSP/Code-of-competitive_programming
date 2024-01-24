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

int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        a[x] = x+1;
    }
    int now = 1;
    vector<int> rd;
    while (now <= n) {
        if (a[now] != now) {
            rd.pb(now);
            now++;
        } else {
            rd.pb(now);
            reverse(rd.begin(), rd.end());
            for (auto c : rd) cout << c << " ";
            rd.clear();
            now++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
