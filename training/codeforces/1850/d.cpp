#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	a[0] = a[1]; 
	int len = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] - a[i - 1] > k) len = 1;
		else len++;
		ans = max(ans, len);
	}
	cout << n - ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int _ = 1;
	cin >> _;
	for (; _--; ) {
		solve();
	}
	
	return 0;
}
