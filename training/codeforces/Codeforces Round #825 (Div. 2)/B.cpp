// Problem: B. Playing with GCD
// Contest: Codeforces - Codeforces Round #825 (Div. 2)
// URL: https://codeforces.com/contest/1736/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Rufu

#include <bits/stdc++.h>
// #define int long long
#define cf int _; cin>>_; while(_--) solve();
using namespace std;
using PII = pair<int,int>;
using ll = long long;

const int N = 100010;
int a[N], b[N];
void solve() {
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	a[n + 1] = 1;
	b[1] = a[1];
	for(int i = 2; i <= n; i ++) {
		b[i] = a[i - 1] * a[i] / (__gcd(a[i - 1], a[i]));
		if(__gcd(b[i], b[i - 1]) != a[i - 1]) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cf
	return 0;
}