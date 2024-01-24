#include <bits/stdc++.h>
#define fi first
#define se second
#define pb emplace_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

// --head--

void solve() {
	ll x, y;
	cin >> x >> y;
	vector<int> v;
	for (int i = y; i <= x; i++) {
		v.pb(i);
	}
	for (int i = x - 1; i > y; i--) {
		v.pb(i);
	}
	cout << SZ(v) << '\n';
	for (auto c : v) {
		cout << c << " ";
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _;
	cin >> _;
	while (_--) solve();
	return 0;
}