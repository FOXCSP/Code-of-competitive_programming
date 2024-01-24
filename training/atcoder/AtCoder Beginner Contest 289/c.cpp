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

int n, m;
int g[15][15], c[15];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        for (int j = 1; j <= c[i]; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for (int mxx = 1; mxx < (1 << (m + 1)); mxx++) {
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < m; i++) {
            if (mxx >> i & 1) {
                for (int j = 1; j <= c[i]; j++) {
                    cnt[g[i][j]]++;
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i]) res++;
        }
        if (res == n) ans ++;
    }
    cout << ans / 2<< '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
