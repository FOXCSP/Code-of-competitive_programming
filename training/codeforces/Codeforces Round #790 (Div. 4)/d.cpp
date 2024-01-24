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

void solve() {
    cin >> n >> m;
    int ans = -1;
    vector<vector<int>> g(n + 2, vector<int> (m + 2, 0));
    vector<vector<int>> s(n + 2, vector<int> (m + 2, 0));
    vector<vector<int>> t(n + 2, vector<int> (m + 2, 0));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> g[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) s[i][j] = s[i - 1][j + 1] + g[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) t[i][j] = t[i - 1][j - 1] + g[i][j];
    for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) t[i][j] = max(t[i][j], t[i + 1][j + 1]);
    for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) s[i][j] = max(s[i][j], s[i + 1][j - 1]);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ans = max(ans, s[i][j] + t[i][j] - g[i][j]);
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
