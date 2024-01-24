// Problem: C1. Good Subarrays (Easy Version)
// Contest: Codeforces - Codeforces Round #825 (Div. 2)
// URL: https://codeforces.com/contest/1736/problem/C1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Rufu

#include <bits/stdc++.h>
#define int long long
#define cf int _; cin>>_; while(_--) solve();
using namespace std;
using PII = pair<int,int>;
using ll = long long;

const int N = 200010;
int a[N];
bool check(int x, int y) {
	return a[y] >= (y - x + 1);
}
void solve() {
	int n; cin >> n;
	for(int i = 0; i <= n + 1; i ++) a[i] = 0;
	for(int i = 1; i <= n; i ++)  cin >> a[i];
	int idx = 1, ans = 0;
	for(int i = 1; i <= n; i ++) {
		if(idx > i && !check(i, idx)) {
			// cout << i << " " << idx << " " << (idx - i - 1) << '\n';
			ans += (idx - i - 1);
			continue;
		}
		int now = 1;
		idx = i;
		while(idx <= n && a[idx] >= now) {
			idx ++, now ++;
		}
		// cout << i << " " << idx << " " << (idx - i - 1) << '\n';
		ans += (idx - i - 1);
	}
	cout << ans + n << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cf
	return 0;
}