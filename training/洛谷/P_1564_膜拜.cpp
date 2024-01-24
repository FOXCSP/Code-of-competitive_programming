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

const int N = 2510;
int n, dp[N], l, r, m, s[N];
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n;i ++) {
        int x;
        cin >> x;
        if(x == 2) s[i] = -1;
        else s[i] = 1;
        s[i] += s[i - 1];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 1;i <= n; i ++) {
        for(int j = 0; j < i; j ++)
            if(abs(s[i] - s[j]) == 0 ||
                abs(s[i] - s[j]) == i - j ||
                abs(s[i] - s[j]) <= m)
                 dp[i] = min(dp[i], dp[j] + 1);
    }
    cout << dp[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
