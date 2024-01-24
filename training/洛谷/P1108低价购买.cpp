#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
#define P(T) pair<T, T>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
// head

const int N = 5010, inf = 1 << 30;
int a[N], n, f[N], dp[N]; 
// dp[i], 以i为结尾的最大下降子序列的长度
// f[i],  以i为结尾的最大下降子序列的方案数
// 1. dp[i] = dp[j] && a[i] == a[j] :   f[i] = f[j];
// 2. dp[i] = dp[j] && a[i] < a[j] :    f[i] += f[j];
// O(N^2); 
void solve(int CaseT) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++)
			if (a[i] < a[j])
				dp[i] = max(dp[i], dp[j] + 1);
	}
	
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (dp[i] == dp[j] && a[i] == a[j])
				f[i] = 0;
			else if (dp[i] == dp[j] + 1 && a[i] < a[j])
				f[i] += f[j];
		}
		if (mp.count(a[i]) == 0 && !f[i])
			++f[i];
		mp[a[i]]++;
//		if (!f[i])
//			f[i]++;
	}
	
//	for (int i = 1; i <= n; i++) {
//		cout << " xx: " << i << " " << dp[i] << " " << f[i] << '\n';
//	}
		
	int mx = -inf, cnt = 0;
	for (int i = 1; i <= n; i++)
		if (mx < dp[i]) {
			mx = dp[i];
			cnt = f[i];
		} else if (mx == dp[i])
			cnt += f[i];
	cout << mx << " " << cnt << '\n';
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

/*
9
46 42 10 12 42 16 3 20 5
*/
