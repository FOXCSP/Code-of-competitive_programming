// Problem: E. Price Maximization
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/E
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

const int N = 2e5 + 10;
int a[N], n, k, ans;

void solve() {
	ll sum = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		sum += a[i] / k;
		a[i] %= k;
	}
	sort(a + 1, a + n + 1);
	for(int l = 1, r = n; l < r;) {
		if(a[l] + a[r] >= k)
			sum ++, r --, l ++;
		else l ++;
	}
	cout << sum << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}