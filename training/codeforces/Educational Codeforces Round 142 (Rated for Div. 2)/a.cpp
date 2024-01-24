#include <bits/stdc++.h>
#define fi first
#define se second
#define all(X) X.begin(), X.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int cnt = 0;
	// priority_queue<int, vector<int>, greater<int>> heap;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) cnt++;
	}
	cout << min(n, n - (cnt/2)*2 + cnt/2) << '\n';
}

int main() {
	int _; cin >> _;
	while (_--)
	solve();
	return 0;
}