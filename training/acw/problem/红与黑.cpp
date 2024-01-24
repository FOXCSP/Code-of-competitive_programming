#include <bits/stdc++.h>

using namespace std;

const int N = 25;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char g[N][N];
int n, m, ans;
void dfs(int x, int y) {
    g[x][y] = '#';
    ans ++;
    for(int i = 0;i < 4;i ++) {
        int a = x + dx[i], b = y + dy[i];
        if(a < 1 || a > n || b < 1 || b > m) continue;
        if(g[a][b] == '#') continue;
        dfs(a, b);
    }
    return ;
}


int main () {
    while(cin >> m >> n, m && n) {
        int x, y;
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m; j ++)
                {
                    cin >> g[i][j];
                    if(g[i][j] == '@') {
                        x = i, y = j;
                    }
                }
        dfs(x, y);
        cout << ans << '\n';
    }
    return 0;
}