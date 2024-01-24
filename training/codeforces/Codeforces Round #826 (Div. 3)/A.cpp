// Problem: A. Compare T-Shirt Sizes
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Rufu

#include <bits/stdc++.h>
// #define int long long
#define cf int _; cin>>_; while(_--) solve();
using namespace std;
using PII = pair<int,int>;
using ll = long long;

map<char, int > mp;
void solve() {
	string s1, s2; 
	cin >> s1 >> s2;
	// cout << s1.back() << ' ' << s2.back() << '\n';
	if(mp[s1.back()] > mp[s2.back()]) {
		cout << ">\n";
	}
	else if(mp[s1.back()] < mp[s2.back()]) {
		cout << "<\n";
	}
	else {
		if(s1.size() > s2.size()) {
			if(s1.back() == 'L') cout << ">\n";
			else cout << "<\n";
		}
		else if(s1.size() < s2.size()) {
			if(s1.back() == 'L') cout << "<\n";
			else cout << ">\n";
		}
		else cout << "=\n";
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	mp['S'] = 1,  mp['M'] = 2, mp['L'] = 3;
	cf
	return 0;
}