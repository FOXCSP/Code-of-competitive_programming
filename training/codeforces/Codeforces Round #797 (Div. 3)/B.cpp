// Problem: B. Array Decrements
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/B
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

const int N = 5e4+10;
int a[N], b[N];
void solve() {
	int n; cin >> n;
	bool f = true;
	int p = 2e9, q = 0;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i ++) cin >> b[i];
	for(int i = 1;i <= n;i ++) {
		if(b[i] > a[i]) {f = false; break;}
		if(a[i] && b[i]) {
			int t = a[i] - b[i];
			if(p == 2e9) p = t;
			else if(p != t) { f = false; break;}
		}
		else {
			q = max(q, a[i] - b[i]);
		}
	}
	// cout << p << " " << q << endl;  
	if(q > p) f = false;
	if(!f) cout << "NO\n";
	else cout  << "YES\n";
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	while(T --) {
		solve();
	}
	return 0;
}