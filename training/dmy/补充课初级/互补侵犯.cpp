#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
// head

ll dp[11][1<<10][100]; // dp[i][j][k]: 第i行的状态是j，放了k个国王的方案数 
int n, k;
bool b[1 << 10];
int v[1 << 10];
void solve(int CaseT) {
	cin >> n >> k;
	dp[0][0][0] = 1;
	
	for (int i = 0; i < 1 << n; i++) {
		for (int j = i; j; j = j & (j - 1))
			v[i]++;
		b[i] = ((i & (i >> 1))==0);
	}
	
	for (int i = 1; i <= n; i++)
		for (int t = 0; t <= k; t++)
			for (int j = 0; j < 1 << n; j++)
				if (dp[i - 1][j][t])
					for (int l = 0; l < 1 << n; l++)
						if ((l & j) == 0 && ((l >> 1) & j) == 0 && ((l << 1) & j) == 0 && b[l])
							dp[i][l][t + v[l]] += dp[i - 1][j][t];
	ll ans = 0;
	for (int i = 0; i < 1 << n; i++)
		ans += dp[n][i][k];
	cout << ans << '\n';
}	

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
//   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
