#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 310;

int p[N], n, m;
struct edge {
    int d, x, y;
    bool operator < (const edge & B) const {
        return B.d > d;
    }
};

vector<edge> e;

int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]);
    return p[x];
}

PII kruskra() {
    PII res = {0, 0};
    sort(e.begin(), e.end());
    for(int i = 1;i <= n;i ++) p[i] = i;
    for(int i = 0; i < e.size(); i ++) {
        int a = e[i].x, b = e[i].y, d = e[i].d;
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            p[pa] = pb;
            res.first ++;
            res.second = max(res.second, d);
        }
    }
    return res;
}



void solve() {
    cin >> n >> m;
    for(int i = 1;i <= m;i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({c, b, a});
    }
    auto ans = kruskra();
    cout << ans.first << " " << ans.second << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
