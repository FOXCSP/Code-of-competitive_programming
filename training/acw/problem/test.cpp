#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, M = 10, INF = 0x3f3f3f3f;

int n, m;
int w[N], s[N];
int f[N][N][M], g[N][N][M];

int get_mod(int x)
{
    return (x % 10 + 10) % 10;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> w[i];
        w[i + n] = w[i];
    }
    for (int i = 1; i <= n * 2; i ++ ) s[i] = s[i - 1] + w[i];

    memset(f, 0x3f, sizeof f);
    memset(g, -0x3f, sizeof g);

    for (int len = 1; len <= n; len ++ )
        for (int l = 1; l + len - 1 <= n * 2; l ++ )
        {
            int r = l + len - 1;
            f[l][r][1] = g[l][r][1] = get_mod(s[r] - s[l - 1]);
            for (int k = 2; k <= m; k ++ )
                for (int j = l + k - 2; j < r; j ++ )
                {
                    f[l][r][k] = min(f[l][r][k], f[l][j][k - 1] * get_mod(s[r] - s[j]));
                    g[l][r][k] = max(g[l][r][k], g[l][j][k - 1] * get_mod(s[r] - s[j]));
                    cout << f[l][j][k - 1] * get_mod(s[r] - s[j]) << "   xxxx\n";

                }
        }

    int maxv = -INF, minv = INF;
    for (int i = 1; i <= n; i ++ )
    {
        maxv = max(maxv, g[i][i + n - 1][m]);
        minv = min(minv, f[i][i + n - 1][m]);
    }

    cout << minv << endl;
    cout << maxv << endl;

    return 0;
}