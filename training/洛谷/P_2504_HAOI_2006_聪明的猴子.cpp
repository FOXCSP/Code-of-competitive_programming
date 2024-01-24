#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 1010;
int p[N], n, m;
struct edge {
    double d;
    int x, y;
    bool operator < (const edge & B) const {
        return d < B.d;
    }
};

int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

vector<edge> e;
double kruskra() {
    sort(e.begin(), e.end());
    int cnt = n;
    for(int i = 1;i <= n;i ++) p[i] = i;
    for(int i = 0;i < e.size(); i ++) {
        double d = e[i].d;
        int x = e[i].x;
        int y = e[i].y;
        int px = find(x), py = find(y);
        if(px != py) {
            p[px] = py;
            cnt --;
        }
        if(cnt == 1) return d;
    }
    return 0;
}

int a[N];
typedef pair<double, double > pdd;
pdd point[N];
double dis(pdd a, pdd b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
void solve() {
    cin >> m;
    for(int i = 1;i <= m;i ++) cin >> a[i];
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        double a, b;
        cin >> a >> b;
        point[i] = {a, b};
    }
    
    for(int i =1;i <= n;i ++) {
        for(int j = 1;j < i; j ++) {
            double d = dis(point[i], point[j]);
            e.push_back({d, i, j});
        }
    }
    double t = kruskra();
    int ans = 0;
    for(int i = 1; i <= m;i ++)
        if(a[i] >= t)
            ans ++;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
