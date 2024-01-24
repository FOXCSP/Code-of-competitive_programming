#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
int dp[N], n, m, k;
int a[N];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= k; i++) dp[i] = a[i];
    int mx = 0;
    for (int i = k+1; i <= n; i++) {
        mx = max(mx, dp[i-k-1]);
        dp[i] = mx + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
//         printf("%d\n", dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}