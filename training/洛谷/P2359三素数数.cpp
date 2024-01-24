#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9+9, N = 10010;
int n, m;
bool vis[N];
int prime[N], cnt;
void Prime() {
	for (int i = 2; i <= 1000; i++) {
		if (!vis[i]) prime[cnt++] = i;
		for (int j = 0; j < cnt && prime[j] * i <= 1000; j++) {
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
ll dp[N][10][10]; // dp[k][i][j] = 枚举到第k位，当前位是i, 前前一位是j的方案
int main() {
	Prime();
	// for (int i = 0; i < 100; i++) 
	// 	printf("%d%c", prime[i], " \n"[i == 99]);
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			dp[2][i][j] = 1;
	for (int k = 3; k <= n; k++)
		for (int now = 0; now <= 9; now++)
			for (int i = 0; i <= 9; i++)
				for (int j = 0; j <= 9; j++) {
					int t = j * 100 + i * 10 + now;
					if (t > 100 && !vis[t])
						dp[k][now][i] = (dp[k][now][i] + dp[k-1][i][j] + mod) % mod;
				}
	ll ans = 0;
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			ans = (ans + dp[n][i][j] + mod) % mod;
	printf("%lld\n", ans);
	return 0;
}