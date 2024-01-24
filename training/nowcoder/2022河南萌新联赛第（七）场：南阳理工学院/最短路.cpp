#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e5+10, M = 2e5+10; 

int p[N];
int l, r;
int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]);
    return x;
}

void init() {
    for(int i = 1;i <= N ;i ++) p[i] = i;
}

struct Edge {
    int a, b, c;
    bool operator < (const Edge & C) const {
        return c < C.c;
    }
};

bool check() {
    return find(l) == find(r);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> e;
    while(m --) {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({a, b, c});
    }
    int q; cin >> q;
    sort(e.begin(), e.end());
    while(q --) {
        init();
        cin >> l >> r;
        if(l == r) {
            cout << "0\n";
            continue;
        }
        for(auto ed : e) {
            int a = ed.a, b = ed.b, c = ed.c;
            int pa = find(a), pb = find(b);
            if(pa != pb) {
                p[pa] = pb;
            }
            if(check()) {
                cout << c << '\n';
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
