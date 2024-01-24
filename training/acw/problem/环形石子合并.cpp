#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define FOR(x, l, r) for(int x = l;x <= r; ++ x)
#define FRO(x, r, l) for(int x = r;x >= l; -- x)
#define For(x, l, r) for(int x = l;x < r;  ++ x)
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

const int N = 110;
int a[N * 2];
int n, m;
int f[N * 2][N * 2];
int g[N * 2][N * 2];
void solve() {
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i]; a[i + n] = a[i];
    }
    // 前缀和
    FOR(i, i, n<<1) a[i] += a[i - 1];
    memset(f, 0x3f, sizeof f);
    memset(g, 0xcf, sizeof g);
    FOR(i, 1, n<<1) f[i][i] = 0, g[i][i] = 0;
    FOR(l, 2, n<<1) FOR(i, 1, (n<<1) - l + 1) {
        int j = i + l - 1;
        FOR(k, 1, j - 1) {
            f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
            g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + a[j] - a[i - 1]);
        }
    }
    int mmin = 1e9, mmax = -1;
    FOR(i, 1, n) {
        mmin = min(mmin, f[i][i + n - 1]);
        mmax = max(mmax, g[i][i + n - 1]);
    }
    cout << mmin << endl << mmax << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
