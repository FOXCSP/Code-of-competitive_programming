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

const int N = 110;
int dp[N][N], n, k, m;

struct book {
    int h, w;
    bool operator < (const book & B) const {
        return h < B.h;
    }
} bo[N];

void solve() {
    cin >> n >> k;
    for(int i = 1;i <= n; i ++) cin >> bo[i].h >> bo[i].w;
    sort(bo + 1, bo + n + 1);
    
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= n; i ++) dp[i][1] = 0;
    for(int i = 2;i <= n;i ++) {
        for(int l = 2; l <= n - k && l <= i; l ++) {
            for(int j = 1;j <= i - 1; j ++)
                dp[i][l] = min(dp[i][l], dp[j][l - 1] + abs(bo[i].w - bo[j].w));
        }
    }
    int ans = 2e9;
    for(int i = 1;i <= n;i ++) ans = min(ans, dp[i][n - k]);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
