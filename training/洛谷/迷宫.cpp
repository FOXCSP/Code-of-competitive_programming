#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N  = 110;
char g[N][N];
bool d[N][N];
int n, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
pii s, t;

bool dfs(int x, int y) {
    if(x == t.first && y == t.second) return true;
    d[x][y] = true;
    for(int i = 0;i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= n) continue;
        if(d[a][b] || g[a][b] == '#') continue;
        if(dfs(a, b)) return true;
    }
    return false;
}

void solve() {
    cin >> n;
    memset(d, false, sizeof d);
    for(int i = 0;i < n;i ++) cin >> g[i];
    cin >> s.first >> s.second >> t.first >> t.second;
    if(g[s.first][s.second] == '#' || g[t.first][t.second] == '#' || !dfs(s.first, s.second)) {
        cout << "NO\n";
    }
    else cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
