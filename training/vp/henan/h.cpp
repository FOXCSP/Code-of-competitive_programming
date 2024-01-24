#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;


int f(long double x) {
	return (x + 0.5);
}

void solve(int CaseT) {
	int n, k;
	cin >> n >> k;
	int mn;
	int mx;
	
	if (n * 2 >= k) {
		mn = (2 * n - k + 2) / 2;
	} else {
		mn = 0;
	}
	
	if (n * 2 >= k) {
		mx = (2 * n + k) / 2;
	} else {
		mx = min(2 * n, k);	
	}
	cout << mn << " " << mx << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	
	int _;
	_=1;
	cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
