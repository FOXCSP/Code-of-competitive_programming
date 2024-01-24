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

const int N = 200010;
int n, c;
void solve() {
    cin >> n >> c;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += i;
    }
    sort(a.begin(), a.end());
    ll sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (sum + a[i] <= c) sum += a[i], cnt++;
        else break;
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
