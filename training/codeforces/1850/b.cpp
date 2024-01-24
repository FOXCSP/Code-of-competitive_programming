#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define pb push_back
#define se second
#define fi first
using namespace std;

void solve() {
	vector<pair<int, int>> vx;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		if (a <= 10) {
			vx.pb({b, i});
		}
	}  
	sort(vx.begin(), vx.end());
	cout << vx.back().se << '\n';
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
