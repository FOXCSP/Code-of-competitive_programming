#include <bits/stdc++.h>

using namespace std;

int main() {
	int _;
	cin >> _;
	while (_--) {
		int cnt = 0;
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			if (x&1) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}