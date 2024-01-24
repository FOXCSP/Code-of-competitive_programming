// Problem: C. Restoring the Duration of Tasks
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/C
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
int a[N], b[N];

void solve() {
	int n; cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = 1;i <= n;i ++) {
		cin >> b[i];
		printf("%d ", min(b[i] - b[i - 1], b[i] - a[i]));
	}
	printf("\n");
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >>T;
	while(T --) {
		solve();
	}
	return 0;
}