#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1010;
int a[N][N];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n ;i ++)
        for(int j = 1;j <= m;j ++)
            cin >> a[i][j];
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        int mmin = 1e9;
        for(int j = 1;j <= m;j ++) 
            mmin = min(mmin, a[i][j]);
        ans = max(ans, mmin);
    }
    for(int i = 1;i <= m;i ++) {
        int mmin = 1e9;
        for(int j = 1;j <= n;j ++) 
            mmin = min(mmin, a[j][i]);
        ans = max(ans, mmin);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
