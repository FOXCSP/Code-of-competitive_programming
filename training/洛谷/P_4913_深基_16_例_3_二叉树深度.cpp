#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 1000010;
int depth[N], q[N];
int h[N], e[N], ne[N], idx;

void add(int a,int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs(int root) {
    memset(depth, 0x3f, sizeof depth);
    depth[root] = 1; depth[0] = 0;
    int hh = 0, tt = -1;
    q[++ tt] = root;
    while(hh <= tt) {
        int t = q[hh ++];
        for(int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if(depth[j] > depth[t] + 1);
                depth[j] = depth[t] + 1, q[++ tt] = j;
        }
    }
}


void solve() {
    int n;
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1;i <= n;i ++) {
        int a, b;
        cin >> a >> b;
        if(a) add(i, a);
        if(b) add(i, b);
    }
    bfs(1);
    cout << *max_element(depth + 1, depth + n + 1) << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
