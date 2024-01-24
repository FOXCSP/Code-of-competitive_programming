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

const int N = 510;
ll g[N][N];
bool st[N][N];
int n, m, k;
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<g[i][j]<<" \n"[j==m];
    //     }
    // }
    ll ans = 0;
    auto calc = [&](int x1, int y1, int x2, int y2)
    {
        return g[x2][y2] - g[x1 - 1][y2] - g[x2][y1 - 1] + g[x1 - 1][y1 - 1];
    };
    int id = 100;
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int x2 = x1; x2 <= n; x2++)
        {
            int y1=1;
            for (int y2 = 1; y2 <= m; y2++) 
            {
                while (y1 <= y2 && calc(x1, y1, x2, y2) > k) y1++;
                if (y2 >= y1) ans += y2 - y1 + 1;
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    for (int i = 1; i <= _; i++)
    {
        solve();
    }
    return 0;
}