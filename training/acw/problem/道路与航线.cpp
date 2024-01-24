#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 25010, M = 100010;

vector<P(int)> e[N];
vector<int> block[N];
int st[N], d[N];
queue<int> que;
int id[N], tot;
int deg[N];
int T, R, P, S;

void dfs(int u) {
    id[u] = tot;
    block[tot].pb(u);
    for (auto [v, w] : e[u]) {
        if (id[v]) continue;
        dfs(v);
    }
}

void dijkstra(int num) {
    priority_queue<P(int), vector<P(int)>, greater<P(int)> > heap;
    for (auto v : block[num]) {
        heap.push({d[v], v});
    }
    while (!heap.empty()) {
        auto [dist, ver] = heap.top(); heap.pop();
        if (st[ver]) continue;
        st[ver] = 1;
        for (auto [nxt, w] : e[ver]) {
            if (id[ver] != id[nxt] ) {
                --deg[id[nxt]];
                if (!deg[id[nxt]]) que.push(id[nxt]);
            }
            if (d[nxt] > dist + w) {
                d[nxt] = dist + w;
                if (id[ver] == id[nxt]) heap.push({d[nxt], nxt});
            }
        }
    }
}

void topsort() {
    for (int i = 0; i <= T; i++) d[i] = 1e9;
    d[S] = 0;
    for (int i = 1; i <= tot; i++) {
        if (deg[i] == 0)
            que.push(i);
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        dijkstra(now);
    }
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> T >> R >> P >> S;

    for (int i = 1; i <= R; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].pb({b, c});
        e[b].pb({a, c});
    }


    for (int i = 1; i <= T; i++) {
        if (!id[i]) ++tot, dfs(i);
    }


    for (int i = 1; i <= P; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].pb({b, c});
        deg[id[b]]++;
    }

    topsort();

    for (int i = 1; i <= T; i++) {
        if (d[i] == 1e9) {
            cout << "NO PATH\n";
        } else {
            cout << d[i] << '\n';
        }
    }
    return 0;
}
