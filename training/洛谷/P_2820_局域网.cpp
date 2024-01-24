#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 110;

struct edge {
    int f, x, y;
    bool operator < (const edge & B) const {
        return f < B.f;
    }
};

int n, m;
vector<edge> e;

int p[N];
int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int kruskra() {
    int ans = 0;
    for(int i = 1; i <= n;i ++) p[i] = i;
    sort(e.begin(), e.end());
    for(int i = 0; i < e.size(); i ++) {
        int x = e[i].x, y = e[i].y, f = e[i].f;
        int px = find(x), py = find(y);
        if(px != py) {
            p[py] = px;
        }
        else {
            ans += f;
        }
    }
    return ans;
}


void solve() {
    cin >> n >> m;
    while(m --) {
        int a, b, c;
        cin >> a >> b >> c;
        if(c) e.push_back({c, a, b});
    }
    int ans = kruskra();
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
