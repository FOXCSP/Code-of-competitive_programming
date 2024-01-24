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

const int N = 300010;
int m, s, t;
int dp[N], w[N];
void solve() {
    cin >> m >> s >> t;
    for(int i = 1;i <= t; i ++ ) {
        if(m >= 10) dp[i] = dp[i - 1] + 60, m -= 10;
        else dp[i] = dp[i - 1], m += 4;
    }

    for(int i = 1;i <= t; i ++) {
        if(dp[i] < dp[i - 1] + 17) dp[i] = dp[i - 1] + 17;
        if(dp[i] >= s) {
            cout << "Yes\n";
            cout << i << '\n';
            return ;
        }
    }
    cout << "No\n";
    cout << dp[t] << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
