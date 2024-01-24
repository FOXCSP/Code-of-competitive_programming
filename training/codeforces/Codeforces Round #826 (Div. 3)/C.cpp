// Problem: C. Minimize the Thickness
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Rufu

#include <bits/stdc++.h>
#define int long long
#define cf int _; cin>>_; while(_--) solve();
using namespace std;
using PII = pair<int,int>;
using ll = long long;

const int N = 2010;
int a[N], ans = 1e18;
int n, sum;
void check(int x) {
	int ave = sum / x;
	int i = 1, tmp = ave, t = 0;
	int res = 0, cnt = 0;
	while(i <= n) {
		tmp -= a[i ++]; t ++;
		if(tmp == 0) {
			cnt ++, tmp = ave;
			res = max(res, t);
			t = 0;
		}
		if(tmp < 0) return ;
	}
	if(cnt != x) return ;
	ans = min(ans, res);
}

void solve() {
	cin >> n;
	ans = 1e18, sum = 0;
	for(int i = 1; i <= n; i ++) cin >> a[i], sum += a[i];
	for(int i = 1; i <= n; i ++) if(sum % i == 0) check(i);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cf
	return 0;
}