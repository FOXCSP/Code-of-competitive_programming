#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2010;
int n, m, x;
int dist1[N][N], dist2[N][N], w[N][N];
int sx, sy, ex, ey;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int ans = 1 << 30;
void bfs1(int s, int t, int a, int b) {
    queue<array<int, 3>> q;
    q.push({s, t, 0});
    memset(dist1, -1, sizeof dist1);
    dist1[s][t] = 0;
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + t[0], y = dy[i] + t[1];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (w[x][y] == -1 || dist1[x][y] != -1) continue;
            dist1[x][y] = t[2] + 1;
            q.push({x, y, dist1[x][y]});
        }
    }
}

void bfs2(int s, int t, int a, int b) {
    queue<array<int, 3>> q;
    q.push({s, t, 0});
    memset(dist2, -1, sizeof dist2);
    dist2[s][t] = 0;
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + t[0], y = dy[i] + t[1];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (w[x][y] == -1 || dist2[x][y] != -1) continue;
            dist2[x][y] = t[2] + 1;
            q.push({x, y, dist2[x][y]});
        }
    }
}

signed main() {
    scanf("%lld%lld%lld", &n, &m, &x);
    scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &w[i][j]);
            if (w[i][j] > x) {
                w[i][j] = 1;
            } else if (w[i][j] != -1) w[i][j] = 0; 
        }
    bfs1(sx, sy, ex, ey);
    bfs2(ex, ey, sx, sy);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) if (w[i][j] == 1) {
            if (dist1[i][j] != -1 && dist2[i][j] != -1) 
                ans = min(ans, dist1[i][j] + dist2[i][j]);
        }
    if (ans == 1 << 30) printf("-1\n"); 
    else printf("%lld\n", ans);
    return 0;
}