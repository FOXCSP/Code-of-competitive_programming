#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define setdb cout<<fixed<<setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

const int N = 100010;
vec<array<int, 3>> edge;
int p[N], n, m;
int find(int x) {
    return x != p[x] ? p[x] = find(p[x]) : x;
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.pb({w, u, v});
    }
    sort(all(edge));
    int ans = 1 << 30;
    for (int i = 0; i < SZ(edge); i++) {
        for (int j = 1; j <= n; j++) p[j] = j;
        int res = n;
        for (int j = i; j < SZ(edge); j++) {
            int px = find(edge[j][1]);
            int py = find(edge[j][2]);
            if (px != py) {
                p[px] = py;
                res--;
            }
            if (res == 1) {
                ans = min(ans, edge[j][0] - edge[i][0]);
                break;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    _ = 1;
    // cin >> _;
    for (int i = 1; i <= _; i++) {
        solve(i);
    }
    return 0;
}