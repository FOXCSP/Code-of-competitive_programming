#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, c;
	cin >> n >> c;
	map<int,int> mp;
	for(int i = 1;i <= n; i ++) {
		int x;
		cin >> x;
		mp[x] ++;
	}
	int res = 0;
	for(auto v : mp) {
		if(v.second > c) res += c;
		else res += v.second;
	}
	cout << res << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}