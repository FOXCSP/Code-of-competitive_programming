#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 55;
char g[N][N];
int n, m;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        // scanf("%s", g[i] + 1);
        cin >> g[i] + 1;
    // for (int i = 1; i <= n; i++)
    //    cout << g[i] + 1 << '\n';
    
    for (int i = 1; i <= m; i++)
        g[n + 1][i] = 'o', g[0][i] = '.';
    for (int j = 1; j <= m; j++)
        for (int i = n; i >= 1; i--) {
            int x = i, y = j;
            while (x <= n && g[x][y] == '*' && g[x + 1][y] != 'o') {
                swap(g[x][y], g[x + 1][y]);
                x++;
            }
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << g[i][j];
        cout << '\n';
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
