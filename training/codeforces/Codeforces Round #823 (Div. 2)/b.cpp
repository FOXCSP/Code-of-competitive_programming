#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
double t[N], a[N], eps = 1e-6, ans;
int n;
bool calc(double x) {
	double l = -1e18, r = 1e18;
	for(int i = 1;i <= n;i ++) {
		if(x <= t[i]) return false;
		else {
			double y = x;
			y -= t[i];
			double L = a[i] - y, R = a[i] + y;
			if(r < L || l > R) return false;
			l = max(l, L);
			r = min(r, R);
			if(l - eps > r) return false;
		}
	}
	ans = l;
	return true;
}
void solve() {
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = 1;i <= n;i ++) cin >> t[i];

	double l = 0.0, r = 1e9;
	while(l + eps < r) {
		double mid = (l + r) / 2;
		if(calc(mid)) r = mid; else l = mid;
	}
	printf("%.12f\n", ans);
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int ca; cin >> ca;
	while(ca --) solve();
	return 0;
}