#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e5+10;
int a[N];
void solve() {
    ll n, m; cin >> n >> m;
    ll sum = (n * (n + 1)) / 2;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        if(a[i] != a[i + 1]) sum += i*(n-i);
        if(a[i] == a[i - 1]) sum -= 1ll*(i-1)*(n-i+1);
    }
    // cout << sum << endl;
    while(m --) {
        ll x, y;
        cin >> x >> y;
        ll p = a[x];
        a[x] = y;
        if(x == 1) {
            if(p == a[x+1] && y != a[x+1]) sum += x*(n-x);
            if(p != a[x+1] && y == a[x+1]) sum -= x*(n-x);
        }
        else if(x == n) {
            if(p == a[x-1] && y != a[x-1]) sum += (x-1)*(n-x+1);
            if(p != a[x-1] && y == a[x-1]) sum -= (x-1)*(n-x+1);
        }
        else {
            if(p == a[x-1] && y != a[x-1]) sum += (x-1)*(n-x+1);
            if(p != a[x-1] && y == a[x-1]) sum -= (x-1)*(n-x+1);
            if(p == a[x+1] && y != a[x+1]) sum += x*(n-x);
            if(p != a[x+1] && y == a[x+1]) sum -= x*(n-x);
        }
        cout << sum <<endl; 
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
