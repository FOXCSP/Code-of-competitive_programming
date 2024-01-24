#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	int ans = n - 3;
	ans /= 3;
	cout << ans - 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}