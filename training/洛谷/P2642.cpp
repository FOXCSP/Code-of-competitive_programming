#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

const int N = 1000010;

int f[N], pre[N], suf[N], n, a[N];
void solve() {
	cin >> n;
	for(int i = 1;i <= n;i ++) { 
		cin >> a[i];
		pre[i] = i == 1 ? a[i] : max(pre[i - 1] + a[i], a[i]);
	}
	for(int i = n;i >= 1; i --) {
		suf[i] = i == n ? a[i] : max(suf[i + 1] + a[i], a[i]);
	}
	for(int i = 2;i <= n;i ++) pre[i] = max(pre[i - 1], pre[i]);
	for(int i = n - 1; i; i --) suf[i] = max(suf[i], suf[i + 1]);
	int ans = -(1ll<<62);
	for(int i = 2;i < n;i ++) {
		ans = max(ans, pre[i - 1] + suf[i + 1]);
	}
	cout << ans << '\n';
}

signed main ()  {
	cin.tie(nullptr) -> sync_with_stdio(false);
	solve();
	return 0;
}