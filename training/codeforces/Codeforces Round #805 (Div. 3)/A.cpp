// Problem: A. Round Down the Price
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int m;
bool check(int mi) {
	int t = qmi(10, mi);
	if(t <= m) return true;
	return false; 
}

void solve() {
	cin >> m;
	int l = 0, r = 9;
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << m - qmi(10, l) << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}