#include <bits/stdc++.h>

using namespace std;


void solve() {
	int n; cin >> n;
	string s; cin >> s;
	map<string, int> mp;
	for(int i = 0; i < s.size() - 1; i ++) {
		string t;
		t += s[i];
		t += s[i + 1];
		mp[t] ++;
	}
	string ans = "";
	int res = 0;
	for(auto c : mp) {
		if(c.second > res) {
			res = c.second;
			ans = c.first;
		}
	}
	cout << ans << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}