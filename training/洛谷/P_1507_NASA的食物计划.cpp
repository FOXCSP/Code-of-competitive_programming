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

const int N = 410;
int f[N][N], n, m1, m2;
void solve() {
    cin >> m1 >> m2;
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        for(int j = m1; j >= v1; j --)
            for(int k = m2; k >= v2; k --)
                f[j][k] = max(f[j][k], f[j - v1][k - v2] + w);
    }
    cout << f[m1][m2] << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
