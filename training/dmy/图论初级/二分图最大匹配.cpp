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

const int N = 5010;
vec<int> e[N];
int p[N], n, m;
int id[N], vis[N], r[N][N], n1, n2;

bool find(int u) {
    vis[u] = 1;
    for (auto v : e[u]) {
        if (!id[v] || (!vis[id[v]] && find(v))) { 
            id[v] = u;
            return true;
        }
    }
    return false;
}

int match() {
    int ans = 0;
    for (int i = 1; i <= n1; i++) {
        memset(vis, false, sizeof vis);
        if (find(i))
            ans++;
    }
    cout << ans << '\n';
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        // add edge
    }
    cout << match() << '\n';
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