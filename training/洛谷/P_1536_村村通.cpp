#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 1010;

int p[N], n, m;
int find(int x) {
    if(x == p[x]) return x;
    else return p[x] = find(p[x]);
}


void init() {
    for(int i = 1; i <= n;i ++) p[i] = i;
}
void solve() {
    while(cin >> n, n) {
        cin >> m;
        init();
        int cnt = n;
        while(m --) {
            int x, y;
            cin >> x >> y;
            int px = find(x), py = find(y);
            if(px != py) {
                p[px] = py;
                cnt --;
            }
        }
        cout << cnt - 1 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
