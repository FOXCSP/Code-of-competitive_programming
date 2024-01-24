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
const int N = 1010;
int n, m, k;
int d[N][N];
char g[N][N];
P(int) S, E;
int bfs() {
    queue<array<int, 3>> que;
    que.push({S.fi, S.se, 0});
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    d[S.fi][S.se] = 1;
    while (!que.empty()) {
        auto t = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = t[0] + dx[i];
            int ny = t[1] + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (g[nx][ny] == 'X' || d[nx][ny] != 0) continue;
            d[nx][ny] = t[2] + 1;
            que.push({nx, ny, d[nx][ny]});
            if (make_pair(nx, ny) == E) return d[nx][ny];
        }
    }
    return -1;
}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> g[i] + 1;
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'S') S = {i, j};
            if (g[i][j] == 'E') E = {i, j};
        }
    }
    cout << bfs() << '\n';
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