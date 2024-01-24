#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 100010;
int a[10][N];
void solve() {
    int n;cin >> n;
    int mt = -1;
    for(int i = 1;i <= n;i ++) {
        int t, x, b;
        cin >> t >> x >> b;
        if(x <= t) a[x][t] = b;
        mt = max(mt, t);
    }

    for(int j = 1;j <= mt; j ++) {
        for(int i = 0;i <= min(4ll, j);i ++) {
            if(i == j) a[i][j] += (a[i - 1][j - 1]);
            else if(i == 0) a[i][j] += max(a[i+1][j -1], a[i][j - 1]);
            else {
                a[i][j] += max(a[i][j - 1], max(a[i + 1][j - 1],a[i - 1][j - 1]));
            }
        }
    }

    int res = 0;
    for(int i = 0;i < 5;i ++) {
        res = max(res, a[i][mt]);
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
