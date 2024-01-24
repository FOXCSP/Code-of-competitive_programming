#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010;
int c[N], n, m;

int query(int x) {
    int res = 0;
    for(; x; x -= (x & -x)) res += c[x];
    return res;
}

void add(int x,int y) {
    for(; x <= N; x += (x & -x)) c[x] += y;
}

void solve() {
    cin >> n >> m;
    while(m --) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if(op == 'x') {
            add(x, y);
        }
        else {
            cout << query(y) - query(x - 1) << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
