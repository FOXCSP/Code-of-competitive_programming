#include <bits/stdc++.h>

using namespace std;

map<int, string> mp;
map<char, int> op;

void init() {
	mp[1] = "1s";mp[2] = "2s";mp[3] = "2p";mp[4] = "3s";mp[5] = "3p";
	mp[6] = "4s";mp[7] = "3d";mp[8] = "4p";mp[9] = "5s";mp[10] = "4d";
	mp[11] = "5p";mp[12] = "6s";mp[13] = "4f";mp[14] = "5d";mp[15] = "6p";
	mp[16] = "7s";mp[17] = "5f";mp[18] = "6d";mp[19] = "7p";
	op['s'] = 1;
	op['p'] = 2;
	op['d'] = 3;
	op['f'] = 4;
}
bool cmp(pair<string, int> a,pair<string, int> b) {
	string x = a.first, y = b.first;
	if(x[0] != y[0]) return x[0] < y[0];
	return op[x[1]] < op[y[1]];
}

void solve() {
	int n; cin >> n;
	vector<pair<string, int>> ans;
	for(int i = 1; i <= 19 && n > 0; i ++) {
		string s = mp[i];
		int x = 0;
		if(s[1] == 's') x = min(2, n), n -= 2;
		else if(s[1] == 'p') x = min(6, n), n -= 6;
		else if(s[1] == 'd') {x = min(10, n);n -= 10;}
		else x = min(14, n), n -= 14;
		// cout << s << x << " ";
		ans.push_back({s, x});
	}
	sort(ans.begin(), ans.end(), cmp);
	for(auto c : ans) {
		cout << c.first << c.second << " ";
	}
	cout << '\n';
}

int main() {
	init();
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}