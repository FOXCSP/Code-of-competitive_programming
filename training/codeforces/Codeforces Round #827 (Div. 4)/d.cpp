#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> id(1010, 0);
	for(int i = 1; i <= n; i ++) {
		int x; cin >> x;
		id[x] = i;
	}
	int ans = -1;
	for(int i = 1; i <= 1000; i ++) {
		for(int j = 1; j <= 1000; j ++) {
			if(id[i] && id[j] && __gcd(i, j) == 1)
				ans = max(ans, id[i] + id[j]);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin >> _; while(_ --) solve();
	return 0;
}