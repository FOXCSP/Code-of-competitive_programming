// Problem: D. Black and White Stripe
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/D
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

const int N = 2e5+10;
int a[N];

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	for(int i = 0;i < s.size();i ++) a[i+1] = (s[i] == 'B') ? 0:1, a[i+1] += a[i];
	int res = 1e9;
	int l = 1, r = l + k - 1;
	while(r <= n) {
		// cout << a[r] - a[l - 1] << endl;
		res = min(res, a[r] - a[l - 1]);
		r ++, l ++;
	}
	cout << res << endl;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	while( T --) {
		// cout << "--ok--\n";
		solve();
	}
	return 0;
}