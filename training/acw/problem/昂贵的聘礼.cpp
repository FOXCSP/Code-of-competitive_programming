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

const int N = 110;
int n, m;
int w[N][N], level[N], p[N];

int dijkstra(int l, int r) {
    vector<int> dist(n + 1, 1e9);
    vector<int> st(n + 1, 0);
    dist[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        int nxt = -1;
        for (int j = 0; j <= n; j++)
            if (!st[j] && (nxt == -1 || dist[nxt] > dist[j]))
                nxt = j;
        st[nxt] = 1;
        for (int j = 1; j <= n; j++) {
            if (level[j] <= r && level[i] >= l)
                dist[j] = min(dist[j], dist[nxt] + w[nxt][j]);
        }
    }
    return dist[1];
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) w[i][j] = 1e9;
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> p[i] >> level[i] >> c;
        w[0][i] = min(p[i], w[0][i]);
        for (int j = 1; j <= c; j++) {
            int x, y;
            cin >> x >> y;
            w[x][i] = min(w[x][i], y);
        }
    }
    int res = 1e9;
    for (int i = level[i] - m; i <= level[i]; i++)
        res = min(res, dijkstra(i, i + m));
    cout << res << '\n';
    return 0;
}
