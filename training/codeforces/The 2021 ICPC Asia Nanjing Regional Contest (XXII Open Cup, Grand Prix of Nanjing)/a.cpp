#include <bits/stdc++.h>


using namespace std;

int n, x, y;
void solve() {
	cin >> n >> x >> y;
	string ans = "";
	int mx = (1 + n) / 2, my = mx;
	if(x >= mx) {
		for(int i = 1;i <= n - 1;i ++) ans += "D";
		if(y <= my) {
			for(int i = 1;i <= n - 1; i ++) ans += "L";
			for(int i = 1;i <= n - x; i ++) ans += "U";
			for(int i = 1;i <= y - 1; i ++) ans += "R";
		}
		else {
			for(int i = 1;i <= n - 1; i ++) ans += "R";
			for(int i = 1;i <= n - x; i ++) ans += "U";
			for(int i = 1;i <= n - y; i ++) ans += "L";
		}
	}
	else {
		for(int i = 1;i <= n - 1;i ++) ans += "U";
		if(y <= my) {
			for(int i = 1;i <= n - 1; i ++) ans += "L";
			for(int i = 1;i <= x - 1; i ++) ans += "D";
			for(int i = 1;i <= y - 1; i ++) ans += "R";
		}
		else {
			for(int i = 1;i <= n - 1; i ++) ans += "R";
			for(int i = 1;i <= x - 1; i ++) ans += "D";
			for(int i = 1;i <= n - y; i ++) ans += "L";
		}
	}
	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}