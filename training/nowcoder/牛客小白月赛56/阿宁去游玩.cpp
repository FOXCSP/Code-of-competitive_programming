#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 4e5 + 10, M = 1e6 + 10;
int h[N], ne[M], e[M], w[M], idx;

void add(int a,int b,int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int n, m;
int x, y, z;
int a[N];
int dist[N];
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > heap;
    heap.push({0, 1});
    while(heap.size()) {
        auto t = heap.top(); heap.pop();
        int d = t.first, ver = t.second;
        if(st[ver]) continue;
        st[ver] = 1;
        for(int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if(dist[j] > d + w[i]) {
                dist[j] = d + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    cin >> x >> y >> z;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        add(i, i + n, z);
        add(i + n, i, z);
    }

    for(int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        if(a[u] == a[v]) {
            add(u, v, x); 
            add(v, u, x);
            add(u + n, v, y);
            add(v + n, u, y);
        }
        else {
            add(u, v, y);
            add(v, u, y);
            add(u + n, v, x);
            add(v + n, u, x);
        }
    }
    cout << dijkstra() << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
