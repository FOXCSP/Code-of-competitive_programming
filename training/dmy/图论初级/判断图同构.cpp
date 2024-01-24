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
const int N = 10;
int a[N][N], b[N][N], c[N], n, m;
bool st[N];
bool dfs(int x) {

    if (x > n) {
        bool ok = 1;
        for (int i = 1; i <= n && ok; i++) {
            for (int j = 1; j <= n && ok; j++) {
                if (a[i][j] != b[c[i]][c[j]])
                    ok = false;
            }
        }
        if (ok) return true;
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            st[i] = 1;
            c[x] = i;
            if ( dfs(x + 1) ) return true;
            st[i] = 0; 
        }
    }
    return false;
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u][v] = b[v][u] = 1;
    }
    if ( dfs(1) ) cout << "Yes\n";
    else cout << "No\n";
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