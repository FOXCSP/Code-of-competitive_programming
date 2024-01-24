#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long

using namespace std; 

const int N = 200010;

int sz[N], p[N];
int n, m, k;
struct Edge {
    int u, v, w;
    bool operator< (const Edge& other) const {
        return w > other.w;
    }
}e[N];
struct Query {
    int d, id;
    bool operator< (const Query& other) const {
        return d > other.d;
    }
}q[N];
int ans[N];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i++) {
        auto& [u, v, w] = e[i];
        cin >> u >> v >> w;
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= k; i++) {
        auto& [d, id] = q[i];
        cin >> d;
        id = i;
    }
    sort(q + 1, q + k + 1);
    int cur = 1, res = 0;
    for (int i = 1; i <= m; i++) {
        auto& [u, v, w] = e[i];
        while (w < q[cur].d) ans[q[cur].id] = res, ++cur;
        int pu = find(u), pv = find(v);
        if (pu == pv) continue;
        p[pu] = pv;
        res += sz[pu] * sz[pv];
        sz[pv] += sz[pu];
    }
    for (; cur <= k; cur++) ans[q[cur].id] = res;
    for (int i = 1; i <= k; i++) cout << ans[i] << '\n';
}

signed main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
