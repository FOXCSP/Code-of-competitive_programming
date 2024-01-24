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
	vector<int> a, b;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x & 1) a.push_back(i);
		else b.push_back(i);
	}
	int la = a.size(), lb = b.size();
	if (la >= 3) {
		cout <<  "YES\n";
		cout << a[0] << " " << a[1] << " " << a[2] << '\n';
	} else if (la >= 1 && lb >= 2) {
		cout << "YES\n";
		cout << a[0] << " " << b[0] << " " << b[1] << '\n';
	} else cout << "NO\n";
}
int main() {
	int _;
	cin >> _;
	while (_--)
	solve();
}

