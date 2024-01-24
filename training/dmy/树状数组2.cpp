#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200010;

int n, m;
template <class T> 
struct BIT {
	T c[N];
	T query(int x) {
		T s = 0;
		for (x; x; x -= x & (-x)) s += c[x];
		return s;
	}
	void modify(int x, T y) {
		for (x; x <= n; x += x & (-x)) c[x] += y;
	}
};
BIT<ll> c1, c2; // c1 d[i] c2 i * d[i]

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int op; cin >> op;
		if (op == 1) {
			ll l, r, d; cin >> l >> r >> d;
			c1.modify(l, d), c1.modify(r + 1, -d);
			c2.modify(l, l * d), c2.modify(r + 1, (r + 1) * (-d));
		}
		else {
			ll x; cin >> x;
			ll ans = (x + 1) * c1.query(x) - c2.query(x);
			cout << ans << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}