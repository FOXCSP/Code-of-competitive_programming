#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define FOR(x, l, r) for(int x = l;x <= r; x ++)
#define FRO(x, r, l) for(int x = r;x >= l; x --)
#define For(x, l, r) for(int x = l;x < r;  x ++)
#define pb push_back
#define rp (p<<1|1)
#define lp (p<<1)
#define endl '\n'
#define fi first
#define se second
// #define int long long

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 210;
int w[N];
int f[N][N];

void solve() {
    int n;
    cin >> n;
    for(int i = 1;i <= n; i ++) {
        cin >> w[i];
        w[i + n] = w[i];
    }
    memset(f, 0xcf, sizeof f);
    for(int i = 0; i <= n * 2;i ++) f[i][i + 1] = 0;

    for(int len = 3; len <= n + 1; len ++)
        for(int i = 1; i + len - 1 <= n * 2; i ++) {
            int j = i + len - 1;
            for(int k = i + 1; k <= j - 1; k ++)
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + w[i] * w[j] * w[k]);
        }
    int res = 0;
    for(int i = 1;i <= n; i ++)
        res = max(res, f[i][i + n]);
    cout << res << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}