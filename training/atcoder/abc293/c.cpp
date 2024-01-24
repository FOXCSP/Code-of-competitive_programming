#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--
const int N = 15;
int n, m;
int g[N][N];
multiset<int> st;
ll ans;
void dfs(int x, int y) {
    // cout << x << "\n";
    if (x == n && y == m) {
        ans++;
        // for (auto x : st) {
        //     cout << x << " ";
        // }
        // cout << '\n';
    }

    if (x + 1 <= n) {
        if (st.find(g[x + 1][y]) != st.end()) return ;
        st.insert(g[x + 1][y]);
        dfs(x + 1, y);
        st.erase(st.find(g[x + 1][y]));
    }

    if (y + 1 <= m) {
        if (st.find(g[x][y + 1]) != st.end()) return ;
        st.insert(g[x][y + 1]);
        dfs(x, y + 1);
        st.erase(st.find(g[x][y + 1]));
    }
    return ;
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    st.insert(g[1][1]);
    dfs(1, 1);
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