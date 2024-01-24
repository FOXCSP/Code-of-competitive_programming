#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1010;
int n, m;
int g[N][N];
int s[N][N];
void solve() {
    memset(g, 0, sizeof g);
    memset(s, 0, sizeof s);
    cin >> n >> m;
    int t = 0;
    for(int i = 1;i <= n; i ++) {
        int a, b;
        cin >> a >> b;
        g[a][b] += a * b;
        t = max({t, a, b});
    }
    for(int i = 1;i <= t;i ++)
        for(int j = 1;j <= t; j ++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] + g[i][j] - s[i - 1][j - 1];
    while(m --)
    {
        int hs,ws,hb,wb;
        cin >> hs >> ws >> hb >> wb;
        hb = std::min(hb, t + 1);
        wb = std::min(wb, t + 1);
        hs = std::min(hs, hb - 1);
        ws = std::min(ws, wb - 1);
        cout << (s[hb - 1][wb - 1] - s[hb - 1][ws] - s[hs][wb - 1] + s[hs][ws]) << endl;;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
