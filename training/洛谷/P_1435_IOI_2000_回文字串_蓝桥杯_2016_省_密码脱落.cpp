#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
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

const int N = 2010;
string s, t;
int dp[N][N];
void solve() {
    int n;
    cin >> t;
    s = t;
    reverse(t.begin(), t.end());
    n = s.size();
    s = "0" + s;
    t = "0" + t;
    for(int i = 1;i <= n; i ++ )
        for(int j = 1;j <= n; j ++)
            if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    cout << n - dp[n][n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
