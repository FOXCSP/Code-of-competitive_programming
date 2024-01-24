#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int n, m;
int dp[N][N][4];
int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= 3; k++)
                dp[i][j][k] = 1e9;
    dp[2][0][0] = 0;
    dp[2][1][1] = 0; dp[2][1][2] = 0;
    dp[2][2][3] = 0;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // dp[i][j][0] = min(dp[i-1][j][0],     dp[i-1][j][2]);
            // dp[i][j][1] = min(dp[i-1][j-1][0],   dp[i-1][j-1][2]+1);
            // dp[i][j][2] = min(dp[i-1][j][1],     dp[i-1][j][3]+1);
            // dp[i][j][3] = min(dp[i-1][j-1][1]+1, dp[i-1][j-1][3]+1);

        	if (i - 1 >= j) {
        		if (j >= 0) dp[i][j][0] = dp[i - 1][j][0];
        		if (j >= 1) dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][2]);
        	}
            if (i - 1 >= j - 1) {
            	if (j - 1 >= 0) dp[i][j][1] = dp[i - 1][j - 1][0];
            	if (j - 1 >= 1) dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][2] + 1);
            }

            if (i - 1 >= j) {
            	if (j >= 1) dp[i][j][2] = dp[i - 1][j][1];
            	if (j >= 2) dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j][3] + 1);
            }

            if (i - 1 >= j - 1) {
            	if (j - 1 >= 1) dp[i][j][3] = dp[i - 1][j - 1][1] + 1;
            	if (j - 1 >= 2) dp[i][j][3] = min(dp[i][j][3], dp[i- 1][j - 1][3] + 1);
            }
        }
    }

    int ans = 1e9;

    
    // for (int i = 3; i <= n; i++) {
    // 	for (int j = 1; j <= m; j++) {
    // 		for (int k = 0; k <= 3; k++) {
    //         	printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);    			
    // 		}
    // 	}
    // }


    for (int i = 0; i <= 3; i++) {
        ans = min(ans, dp[n][m][i]);
    }
    cout << ans << '\n';


    return 0;
}