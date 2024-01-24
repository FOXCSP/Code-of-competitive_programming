// Problem: A. Make A Equal to B
// Contest: Codeforces - Codeforces Round #825 (Div. 2)
// URL: https://codeforces.com/contest/1736/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Rufu

#include <bits/stdc++.h>
// #define int long long
#define cf int _; cin>>_; while(_--) solve();
using namespace std;
using PII = pair<int,int>;
using ll = long long;

void solve() {
	int n, m, a = 0, b = 0;
	int s1[110], s2[110];
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> s1[i];
	for(int i = 0; i < n; i ++) cin >> s2[i];
	for(int i = 0; i < n; i ++) 
		if(s1[i] != s2[i]) a ++;
	sort(s1, s1 + n);
	sort(s2, s2 + n);
	for(int i = 0; i < n; i ++)
		if(s1[i] != s2[i]) b ++;
	cout << min(b + 1, a) << '\n'; 
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cf
	return 0;
}