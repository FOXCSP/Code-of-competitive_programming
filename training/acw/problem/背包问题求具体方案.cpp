#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1010;
int f[N][N], n, m, v[N], w[N];
void solve() {
    // memset(f, 0xcf, sizeof f);
    cin >> n >> m;
    // f[1][0] = 0;
    for(int i = 1;i <= n;i ++ ) cin >> v[i] >> w[i];
    for(int i = n;i >= 1;i --) {
        for(int j = 0;j <= m; j ++) {
            f[i][j] = f[i + 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        } 
    }
    // output
    int j = m;
    for(int i = 1; i <= n; i ++) {
        if(j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i]) {
            cout << i << " ";
            j -= v[i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
