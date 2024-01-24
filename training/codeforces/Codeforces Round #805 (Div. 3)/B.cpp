// Problem: B. Polycarp Writes a String from Memory
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/B
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


string s;
void solve() {
	cin >> s;
	int day = 0;
	map<char, int> mp;
	for(int i = 0;i < s.size();i ++) {
		if(mp.count(s[i])) continue;
		else if(mp.size() == 3) {
			mp.clear();
			day ++;
		}
		mp[s[i]] ++;
	}
	cout << day+1 << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}