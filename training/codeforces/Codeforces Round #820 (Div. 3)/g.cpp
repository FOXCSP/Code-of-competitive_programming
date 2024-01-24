#include <bits/stdc++.h>


using namespace std;

const int N = 510, mod = 1e9 + 7;
string s, t;
int ls, lt;
bool st[N];
int dp[N][N][2];

void solve() {
	memset(st, 0, sizeof st);
	memset(dp, 0, sizeof dp);
	cin >> s >> t;
	ls = s.size();
	lt = t.size();
	s = "?" + s;
	t = "/" + t;
	for(int i = 1; i + lt - 1 <= ls; i ++) {
		bool f = true;
		for(int j = 1, k = i;j <= lt; k ++, j ++) {
			if(s[k] != t[j]) f = false;
		}
		if(f) st[i + lt - 1] = true;
	}

	dp[0][0][0] = 1;
	for(int i = 1;i <= ls; i ++) {
		for(int j = 0; j <= i; j ++ ) {
			if(!st[i]) dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
			else {
				if(j > 0 && i - lt >= 0) dp[i][j][1] = (dp[i - lt][j - 1][0] + dp[i - lt][j - 1][1]) % mod;
				for(int k = i - lt + 1; k < i; k ++ ) dp[i][j][0] = (dp[i][j][0] + dp[k][j][1]) % mod;
			}
		}
	}
	int res = 0;
	for(int i = 0; i <= ls; i ++) {
		res = max(res, dp[ls][i][0] + dp[ls][i][1]);
		if(res > 0) {
			cout << i << " " << res << '\n';
			return ;
		}
	}
}


int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}