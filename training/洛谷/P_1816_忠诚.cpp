#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;


const int N = 100010;
int f[N][100], a[N];

int n, q;
void ST() {
    memset(f, 0x3f, sizeof f);
    for(int i = 1;i <= n;i ++) f[i][0] = a[i];
    int t = log(n)/log(2)+1;
    for(int j = 1;j < t;j ++)
        for(int i = 1;i <= n - (1<<j)+1; i ++) 
            f[i][j] = min(f[i][j-1], f[i + (1 << (j -1))][j-1]);
}

int query(int l,int r) {
    int k = log(r - l + 1) / log(2);
    return min(f[l][k], f[r - (1<<k) + 1][k]);
}
void solve() {
    cin >> n >> q;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    ST();
    while(q --) {
        int a,b;
        cin >> a >> b;
        cout << query(a, b) << " \n"[q == 0];    
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
