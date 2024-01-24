#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 2010, M = 10010;
int p[N], n, m;

struct edge {
    int a, b, d;
    bool operator < (const edge & B) const {
        return d < B.d;
    }
};


int find(int x) {
    if(x == p[x]) return x;
    else return p[x] = find(p[x]);
}

vector<edge> e;

int kruskra() {
    sort(e.begin(), e.end());
    int res = 0;
    for(int i = 1; i <= n; i ++) p[i] = i;
    for(int i = 0;i < e.size(); i ++) {
        int a = e[i].a, b = e[i].b, d = e[i].d;
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            p[pa] = pb;
            res = max(res, d);
        }
    }
    return res;
}

void solve() {
    cin >> n >> m;
    while(m --) {
        int a, b,c;
        cin >> a >> b >> c;
        e.push_back({a, b, c});
    }
    cout << kruskra() << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
