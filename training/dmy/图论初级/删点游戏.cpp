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

const int N = 310, inf = 1 << 30;
int n, m, k;
int d[N][N];
int ins[N];
int a[N];
void solve(int CaseT) {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = inf;

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            cin >> d[i][j];
    
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans[N] = {0};
    for (int i = n; i >= 1; i--) {
        ins[a[i]] = 1;
        for (int p = 1; p <= n; p++)
            for (int q = 1; q <= n; q++)
                d[p][q] = min(d[p][q], d[p][a[i]] + d[a[i]][q]);
        int res = 0;
        for (int p = 1; p <= n; p++) {
            for (int q = 1; q <= n; q++) {
                if (ins[p] && ins[q])
                    res += d[p][q];
            }
        }
        ans[i] = res;
    }
    
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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