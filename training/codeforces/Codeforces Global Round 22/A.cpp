#include <bits/stdc++.h>
#define int long long

using namespace std;
using PII = pair<int,int>;
using ll = long long;

const int N = 100010;
int n, a[N], b[N], c[N], ans = 0;
void solve() {
	cin >> n;
	ans = 0;
	for(int i = 1;i <= n;i ++) cin >> c[i];
	int l1 = 1, l2 = 1;
	for(int i = 1;i <= n;i ++) {
		if(c[i]) cin >> b[l2], l2 ++;
		else cin >> a[l1], l1 ++;
	}
	sort(a + 1, a + l1), l1 --;
	sort(b + 1, b + l2), l2 --;
	if(l1 == l2) ans -= min(a[1], b[1]);
	while(l1 && l2) {
		ans += 2ll * (a[l1] + b[l2]);
		l1 --, l2 --;
	}
	while(l1) {ans += a[l1]; l1 --;}
	while(l2) {ans += b[l2]; l2 --;}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}