#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
using ll = long long;
int n, m;

ll c[N], a[N];
void modify(int x, ll y) {
	for (x; x <= n; x += x & (-x)) c[x] += y;
}

int query(ll s) {
	int pos = 0;
	for (int j = 18; j >= 0; j --) {
		if (pos + (1 << j) <= n && c[pos + (1ll << j)] <= s) {
			pos += (1 << j);
			s -= c[pos];
		}
	}
	return pos;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		modify(i, a[i]);
	}
	for (int i = 0; i < m; i++) {
		int op; cin >> op;
		if (op == 1) {
			int x, d; cin >> x >> d;
			modify(x, d - a[x]);
			a[x] = d;
		}
		else {
			ll s; cin >> s;
			ll t = query(s);
			cout << t << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}