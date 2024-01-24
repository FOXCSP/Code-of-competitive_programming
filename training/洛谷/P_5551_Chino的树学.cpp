#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 30;

int n, m;
int a[N];

// void build(int p,int l, int r) {
//     if(l == r) {
//         cin >> a[l];
//         return ;
//     }
//     int mid = l + r >> 1;
//     build(p<<1, l, mid);
//     build(p<<1|1, mid+1, r);
// }

int f[N];

int dfs(int dep, int u) {
    int res;
    cin >> res;
    return ++ dep > n ? res : res + max(dfs(dep, u<<1), dfs(dep, u<<1|1));
}

void solve() {
    cin >> n;
    // build(1, 1, (1<<n) - 1);
    cout << dfs(1, 1) << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
