#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	k = min(k, 30);
	while ((1 << k) >= n) k--;
	if (k == -1) {
		cout << 2 << '\n';
		return ;
	}
//	if (k == 0) k++;
	int ans = (1 << k) + (k == 0);
	if (n == (1 << (k + 1)))
		ans++;
	cout << ans << " " << k << '\n';
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
