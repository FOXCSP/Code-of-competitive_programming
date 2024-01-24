#include <bits/stdc++.h>

using namespace std;

int n;
void solve() {
	cin >> n;
	map<int, int> mp;
	int t = 840;
	for(int i = 2; i <= t/i; i ++) {
		while(t % i == 0) mp[i] ++, t /= i;
	}
	if(t > 1) mp[t] ++;
	for(auto c : mp) {
		cout << c.first << " " << c.second << '\n';
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}