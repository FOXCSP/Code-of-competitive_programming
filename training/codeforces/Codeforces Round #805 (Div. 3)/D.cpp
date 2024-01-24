// Problem: D. Not a Cheap String
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}



void solve() {
	string s, t;
	int m;
	cin >> s >> m;
	t = s;
	sort(t.begin(), t.end());
	unordered_map<char, int> mp;
	int len = t.size();
	ll sum = 0;
	for(int i = 0;i < len; i ++) sum += t[i] - 'a' + 1;
	for(int i = len - 1;i >= 0; i--) {
		int x = t[i] - 'a' + 1;
		if(sum > m) {
			sum -= x;
			mp[t[i]] ++;
		} else {
			break;
		}
 	}
 	for(int i = 0;i < len ;i ++) {
 		int x = mp[s[i]];
 		if(x) mp[s[i]] --;
 		else cout << s[i];
 	}
 	cout << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int ca; cin >> ca;
	while(ca --) {
		solve();
	}
	return 0;
}