#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head


void solve() {
	int n;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(b.begin(), b.end());
	if (*b.begin() == b.back()) {
		cout << "-1\n";
	} else {
		int p = n - 2;
		while (p >= 0 && b[p] == b.back())
			p--;
		if (p < 0) {
			cout << "-1\n";
		} else {
			cout << p + 1 << " " << n - (p + 1) << '\n';
			for (int i = 0; i <= p; i++) {
				cout << b[i] << " \n"[i == p];
			}
			for (int i = p + 1; i < n; i++) {
				cout << b[i] << " \n"[i == n - 1];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	cin >> _;

	while (_--) {
		solve();
	}
	return 0;
} 
