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

int n,m;

void solve() {
    cin >> n;
    vector<int> a(n + 1, 0);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int mx1 = 0, mx2 = 0;
    for (auto [x, c] : mp) {
        mx2=mx1;
        mx1=x;
    }
    if (mp[mx1]>1 || mx2==mx1-1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
