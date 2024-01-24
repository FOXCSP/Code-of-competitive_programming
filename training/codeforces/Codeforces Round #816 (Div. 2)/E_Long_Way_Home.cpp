#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e5+10;
int a[N];
void solve() {
    int n, m; cin >> n >> m;
    ll sum = (ll)(n * (n + 1)) / 2;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        if(a[i] != a[i + 1]) sum += (ll)i*(n-i);
    }
    // cout << sum  << endl;
    while(m --) {
        int x, y; cin >> x >> y;
        int p = a[x];
        a[x] = y;
        if(x == 1) {
            if(p == a[x+1] && y != a[x+1]) sum += (ll)x*(n-x);
            if(p != a[x+1] && y == a[x+1]) sum -= (ll)x*(n-x);
        }
        else if(x == n) {
            if(p == a[x-1] && y != a[x-1]) sum += (ll)(x-1)*(n-x+1);
            if(p != a[x-1] && y == a[x-1]) sum -= (ll)(x-1)*(n-x+1);
        }
        else {
            if(p == a[x-1] && y != a[x-1]) sum += (ll)(x-1)*(n-x+1);
            if(p != a[x-1] && y == a[x-1]) sum += (ll)(x-1)*(n-x+1);
            if(p == a[x+1] && y != a[x+1]) sum += (ll)x*(n-x);
            if(p != a[x+1] && y == a[x+1]) sum -= (ll)x*(n-x);
        }
    }
    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
