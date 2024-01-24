// Problem: G. Count the Trains
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/G
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
	int n; cin >> n;
	int m = n - 3;
	int h1, h2, h3;
	h3 = (m)/3;
	m %= 3;
	m += 2;
	h2 = m/2;
	m %= 2;
	m += 1;
	h1 = m;
	cout << h2+h3 << ' ' << h1+h2+h3 << ' ' << h3 << endl;
}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	while(T -- ) {
		solve();
	}
	return 0;
}