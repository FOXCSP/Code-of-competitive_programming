#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = N * 2;
int a[M];
void solve() {
	int n; cin >> n;
	for(int i = 1;i <= n; i ++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	int mn = 0;
	for(int i = 1;i <= )
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}