#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define setdb cout<<fixed<<setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

const int N = 100010;
int n, m;
int f[21][(1<<20)];
int g[21][21], k;
void solve(int CaseT) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    
    memset(f, 0x3f, sizeof f);
    
    for (int i = 0; i < n; i++) f[i][1] = 0;
    
    for (int sta = 0; sta < (1 << n); sta++)
        if (sta & 1)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i != j)
                        if ((sta >> i & 1) && (sta >> j & 1))
                            f[j][sta] = min(f[j][sta], f[i][sta - (1 << j)] + g[i][j]);
    int ans = 1 << 30;
    for (int i = 1; i < n; i++) {
        ans = min(ans, f[i][(1<<n)-1] + g[i][0]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    // cin >> _;
    for (int i = 1; i <= _; i++) {
        solve(i);
    }
    return 0;
}