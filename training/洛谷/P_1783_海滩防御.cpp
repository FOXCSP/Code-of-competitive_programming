#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

struct Edge {
    int x, y;
    double w;
    bool operator < (const Edge& b) const {
        return w < b.w;
    }
};
vector<Edge> E;
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

const int N = 1000, M = 4e5+10;
int p[M], n, m;
int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]);
    return p[x];
}
void  Kruskal() {
    double ans;
    sort(E.begin(), E.end());
    for(auto e : E) {
        int pa = find(e.x), pb = find(e.y);
        if(pa != pb) {
            p[pb] = pa;
        }
        if(find(0) == find(n+1)) {
            ans = e.w;
            break;
        }
    }
    printf("%.2f\n", ans);
}


void solve() {
    cin >> n >> m;
    for(int i = 0;i <= n+1;i ++) p[i] = i;
    vector<pair<double,double>> point(m+1);
    for(int i = 1;i <= m;i ++) {
        double x, y; cin >> x >> y;
        point[i] = {x ,y};
    }

    for(int i = 1;i <= m; i ++) {
        for(int j = i+1;j <= m;j ++) {
            #define fi first
            #define se second
            double w = distance(point[i].fi, point[i].se, point[j].fi, point[j].se);
            E.push_back({i, j, w/2.0});
            // cout << w/2.0 << endl;
        }
    }
    for(int i = 1;i <= m;i ++) {
        E.push_back({0, i, point[i].fi});
        E.push_back({i, n+1, (n-point[i].fi)});
        // cout << point[i].first << " " << (n-point[i].first) << endl;
    }
    // cout << point[1].first << endl;
    // cout << E.size() << endl;
    // for(auto e : E) {
    //     cout << e.x << " " << e.y << '\n';
    // }
    Kruskal();
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
