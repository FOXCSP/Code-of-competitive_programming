#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	vector<int> v(n + 1, 0);
	int sum = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	vector<int> dp(sum + 1, 0);
	
	dp[0] = 1;
	
	for (int i = 1; i <= n; i++)
		for (int j = sum; j >= v[i]; j--)
			dp[j] |= dp[j - v[i]];
	

	for (int i = x; ; i++) {
		if (dp[i]) {
			cout << i << "\n";
			return 0;
		}
	}
	
	return 0;
} 
