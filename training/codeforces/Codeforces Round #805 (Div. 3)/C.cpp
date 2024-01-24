// Problem: C. Train and Queries
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
 
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}
 
 
const int N = 4e5+10;
 
int n, m;
void solve() {
	scanf("%d%d", &n, &m);
	map<int,pair<int,int>> mp;
	for(int i = 1; i <= n;i ++) {
		int a;
		scanf("%d", &a);
		if(mp.count(a) == 0) {
			mp[a].fi = i;
			mp[a].se = i;
		} else {
			mp[a].se = i;
		}
	}
	while(m --) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(mp.count(a) == 0 || mp.count(b) == 0 || mp[a].fi > mp[b].se) printf("NO\n");
		else printf("YES\n");
	}
}
 
int main() {
	int t; cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}