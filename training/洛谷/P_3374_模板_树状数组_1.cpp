#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 500010;
int c[N], n, m, a[N];

void add(int x ,int y) {
    for(; x <= n; x += x & -x) c[x] += y;
}

int query(int x) {
    int ans = 0;
    for(; x; x -= x & -x) ans += c[x];
    return ans;
}

void solve() {
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        add(i, a[i]);
    }
    while(m --) {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1) {
            add(x, y);
        }
        else cout << query(y) - query(x - 1) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
