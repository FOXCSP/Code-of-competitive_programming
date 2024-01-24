#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int d[110];
	int a[110];
	for(int i = 1; i <= n; i ++) cin >> d[i];
	a[1] = d[1];
	for(int i = 2; i <= n; i ++) {
		int x = a[i - 1] + d[i];
		int y = a[i - 1] - d[i];
		if(x >= 0 && y >= 0 && x != y) {
			cout << "-1\n";
			return ;
		}
		a[i] = max(x, y);
	}
	for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}