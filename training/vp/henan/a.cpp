#include <bits/stdc++.h>

using namespace std;

bool ok1(string s) {
	map<char, int> mp;
	for (auto x : s) {
		mp[x]++;
	}
	if (mp.size() != s.size()) return false;
	return true;
}

bool ok2(string s) {
	int l = 0, r = s.size() - 1;
	while (l < r && s[l] == s[r]) {
		l++, r--;
	}
	if (l < r) return false;
	return true;
}


void solve(int CaseT) {
	string s;
	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		string a = s.substr(0, i);
		string b = s.substr(i);
		if (b.size() == 0 || a.size() > 26) {
			cout << "NaN\n";
			return ;
		}
		if (!ok1(a)) {
			cout << "NaN\n";
			return ;
		}
		if (ok2(b)) {
			cout << "HE\n";
			return ;
		}
	}
	cout << "NaN\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_=1;
	cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
