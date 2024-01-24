// Problem: B. Funny Permutation
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Rufu

#include <bits/stdc++.h>
// #define int long long
#define cf int _; cin>>_; while(_--) solve();
using namespace std;
using PII = pair<int,int>;
using ll = long long;

const int N = 200010;
int a[N];
void solve() {
	int n;
	cin >> n;
	if(n == 3) {
		cout << "-1\n";return ;
	}
	for(int i = n, j = 1; i >= 1; i --, j ++) a[j] = i;
	if(n & 1) {
		if(n == 5) swap(a[(n + 1) / 2], a[n]); 
		else swap(a[(n + 1) / 2], a[(n + 1) / 2 - 1]);
	}
	for(int i = 1; i <= n; i ++) {
		cout << a[i] << " \n"[i == n];
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cf
	return 0;
}