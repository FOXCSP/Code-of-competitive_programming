#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	map<int,int> mp;
	for(int i = 1;i <= 5;i ++) {
		int x;
		cin >> x;
		mp[x] ++;
	}
	cout << mp.size() << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}