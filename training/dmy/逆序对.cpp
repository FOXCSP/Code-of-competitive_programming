#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200010;

int n, m, a[N];
template<class T>
struct BIT {
	T c[N];
	T query(int x) {
		T s = 0;
		for (x; x; x -= x & (-x)) s += c[x];
		return s;
	}
	void modify(int x,int y) {
		for (x; x <= n; x += x & (-x)) c[x] += y;
	}
};
BIT<int> c;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = n; i >= 1; i --) {
		ans += c.query(a[i] - 1);
		c.modify(a[i], 1);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}