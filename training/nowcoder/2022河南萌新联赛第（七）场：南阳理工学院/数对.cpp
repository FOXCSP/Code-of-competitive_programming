#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e5+10;
int n, m;
int a[N][40];

int get(int x) {
    return x == 0 ? 0 : (__lg(x));
}
int num[N];

void solve() {
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        int x; cin >> x;
        x = get(x);
        // cout << x << " ";
        a[i][x] = 1;
        // num[get(a[i][1])] ++;
        for(int j = 0; j < 31; j ++) a[i][j] += a[i-1][j];
    }
    for(int l, r, res; m; m --) {
        cin >> l >> r;
        res = 0;
        for(int i = 0;i < 31; i ++) {
            int cnt = a[r][i] - a[l - 1][i];
            res += (cnt - 1) * cnt / 2;
        }
        cout << res << endl;
    }

}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
