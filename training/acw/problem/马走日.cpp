#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 9;
int n, m, ans, x, y;
bool st[N][N];
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

void dfs(int x,int y, int num) {
    // cout << x << " " << y << "\n";
    if(num == n * m) {
        ans ++;
        return ;
    }
    for(int i = 0; i < 8; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m) continue;
        if(st[a][b]) continue;
        st[a][b] = true;
        dfs(a, b, num + 1);
        st[a][b] = false;
    }
    return ;
}

void solve() {
    cin >> n >> m >> x >> y;
    ans = 0;
    memset(st, 0, sizeof st);
    st[x][y] = 1;
    dfs(x, y, 1);
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
