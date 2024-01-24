#include <bits/stdc++.h>

#define fi first
#define se second
#define all(X) X.begin(), X.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve() {
	int cnt = 0, ans = 0, x = 1, now = 0;
	cin >> cnt;
	while (cnt) {
		cout << "- " << x << endl;
		cin >> now;
		ans += 1 << (now - cnt + 1);
		x = 1 << (now - cnt + 1);
		cnt--;
	}
	cout << "! " << ans << endl;
}

int main() {
	int _;
	cin >> _;
	while (_--)
	solve();
	return 0;
}