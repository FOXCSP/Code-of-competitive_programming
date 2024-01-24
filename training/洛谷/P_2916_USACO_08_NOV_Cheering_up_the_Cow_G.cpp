#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010;
int n, m;
int a[10010], p[10010];
struct edge {
    int d, x, y;
    bool operator < (const edge & B) const {
        return d < B.d;
    }
};

int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]);
    return p[x];
}


vector<edge> e;
void solve() {
    cin >> n >> m;
    for(int i = 1;i <= n; i ++) p[i] = i;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    while(m --) {
        int x, y, d;
        cin >> x >> y >> d;
        e.push_back({a[x] + a[y] + 2 * d, x, y});
    }
    // for(auto v : e ) {
    //     cout << v.x << " " << v.y  << " " << v.d << endl;
    // }
    sort(e.begin(), e.end());
    int ans = 0, st = 2e9;
    for(int i = 0;i < e.size(); i ++) {
        int x = e[i].x, y = e[i].y, d = e[i].d;
        int px = find(x), py = find(y);
        if(px != py) {
            p[py] = px;
            ans += d;
            st = min({st, a[x], a[y]});
        }
    }
    std::cout << ans + st << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
