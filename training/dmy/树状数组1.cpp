#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200010;
int n, m;
ll c[N], a[N];
void modify(int x, ll y) {
	for (; x <= n; x += x & (-x)) c[x] += y;
}

ll query(int x) {
	ll res = 0;
	for (; x; x -= x & (-x)) res += c[x];
	return res;
}

void solve () {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		modify(i, a[i]);
	}
	while (m --) {
		int op; cin >> op;
		if (op == 1) {
			ll x, d; cin >> x >> d;
			modify(x, d - a[x]);
			a[x] = d;
		}
		else {
			int x; cin >> x;
			cout << query(x) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}