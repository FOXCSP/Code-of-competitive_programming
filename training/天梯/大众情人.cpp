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

map<int, int> gnd;
const int N = 510, inf = 0x3f3f3f3f;
int g[N][N];

void solve() {
    int n;
    cin >> n;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        if (ch == 'F') gnd[i] = 1;
        else gnd[i] = 0;
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x, di;
            scanf("%d:%d", &x, &di);
            g[i][x] = di;
        }
    }
    for (int t =  1; t <= n; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][t] + g[t][j]);
            }
        }
    }
    vector<pair<double, int>> ans;
    for (int j = 1; j <= n; j++) {
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (i == j || g[i][j] > inf / 2) continue;
            if (gnd[j] ^ gnd[i] == 1) mx = max(mx, g[i][j]);
            // if (j == 2) 
            // cout << i << " -> " << j << " = " << g[i][j] << '\n';

            // if (j == 3) 
            // cout << i << " -> " << j << " = " << g[i][j] << '\n';

            // if (j == 1) 
            // cout << i << " -> " << j << " = " << g[i][j] << '\n';


        }
        ans.pb({mx, j});
    }
    sort(ans.begin(), ans.end());
    // for (int i = 0; i < SZ(ans); i++) {
    //     cout << ans[i].fi << " " << ans[i].se << '\n';
    // }

    // reverse(ans.begin(), ans.end());


    vector<int> a, b;
    int ma, mb;
    for (auto [x, y] : ans) {
        if (gnd[y] == 1 && (!SZ(a) || ma == x)) {
            a.pb(y);
            ma = x;
        }

        if (gnd[y] == 0 && (!SZ(b) || mb == x)) {
            b.pb(y);
            mb = x;
        }
    }
    // cout << SZ(a) << '\n';
    for (int i = 0; i < SZ(a); i++) {
        cout << a[i] << " \n"[i == SZ(a) - 1];
    }
    // cout << SZ(b) << '\n';
    for (int i = 0; i < SZ(b); i++) {
        cout << b[i] << " \n"[i == SZ(b) - 1];
    }
}

int main()
{
    solve();
    return 0;
}
