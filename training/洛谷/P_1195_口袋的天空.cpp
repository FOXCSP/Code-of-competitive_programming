#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 10010;
int n, k, m;
int p[N];

struct edge {
    int d, x, y;
    bool operator < (const edge & B) const {
        return d < B.d;
    }
};

int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]);
    return x;
}

int len ;
vector<int> gr[N];
bool st[N];
vector<edge> e;
void solve() {
    cin >> n >> m >> k;
    for(int i = 1;i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({c, a, b});
    }
    sort(e.begin(), e.end());
    int ans = 0, num = n;

    for(int i = 1;i <= n;i ++) p[i] = i;
    for(int i = 0; i < e.size(); i ++) {
        int x = e[i].x, y = e[i].y, d = e[i].d;
        int px = find(x), py = find(y);
        if(px != py) {
            p[px] = py;
            num --;
            ans += d;
        }
        if(num == k) {
            break;
        }
    }
    if(num == k) cout << ans << "\n";
    else cout << "No Answer\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
