#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 2010;
int a[N], n, m;

void solve() {
    cin >> n;
    int mmax = -2e9, mmin = 2e9;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        mmax = max(mmax, a[i]);
        mmin = min(mmin, a[i]);
    }
    if(a[1] == mmin || a[n] == mmax) {
        cout << mmax - mmin << '\n';
    }
    else {
        int ans = 0;
        for(int i = 1; i < n;i ++) ans = max(ans, a[i] - a[i+1]);
        int x = a[n] - mmin;
        int y = mmax - a[1];
        ans = max({ans, x, y});
        cout << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
