#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 510;
int n, p[N], m, s;
int find(int x) {if(x != p[x]) return p[x] = find(p[x]); return x;}

struct edge {
    int x, y;
    double d;
    bool operator < (const edge & B) const {
        return d < B.d;
    }
};
typedef pair<double, double> pdd;
pdd point[N];
vector<edge> e;
double kruskra() {
    int cnt = n;
    sort(e.begin(), e.end());
    for(int i = 1;i <= n;i ++) p[i] = i;
    for(int i = 0; i < e.size(); i ++) {
        int x = e[i].x, y = e[i].y;
        double d = e[i].d;
        int px = find(x), py = find(y);
        if(px != py) {
            cnt --;
            p[px] = py;
            if(cnt == s) {
                return d;
            }
        }
    }
    return 0;
}

double dis(pdd a, pdd b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void solve() {
    cin >> s >> n;
    for(int i = 1;i <= n;i ++) {
        double a, b; cin >> a >> b;
        point[i] = {a, b};
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1; j < i;j ++) {
            e.push_back({i, j, dis(point[i], point[j])});
        }
    }
    printf("%.2f\n", kruskra());
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
