#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 10000010;
int a[N], c[N], n, m;

void add(int x,int y) {
    for(; x <= n; x += x & -x) c[x] += y;
}

int query(int x) {
    int res = 0;
    for(; x; x -= x & -x) res += c[x];
    return res;
}



void solve() {
    cin >> n >> m;
    for(int i = 1;i <= m;i ++) {
        int op;
        cin >> op;
        if(op == 0) {
            int a, b;
            cin >> a >> b;
            add(a, 1), add(b + 1, -1);
        }
        else {
            int a;
            cin >> a;
            cout << query(a) << "\n";
        }
    }    
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
