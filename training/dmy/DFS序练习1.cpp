#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200010;
vector<int> e[N];
int l[N], r[N], w[N], n, q, tot;

template<class T>
struct BIT {
	T c[N];
	void modify(int x, int v) {
		for (x; x <= n; x += x & -x) c[x] += v;
	}
	T query(int x) {
		T s = 0;
		for (x; x; x -= x & -x) s += c[x];
		return s;
	}
};
BIT<ll> c1, c2; // c1 区间修改, c2单点修改

void dfs(int u, int f) {
	l[u] = ++tot;
	for (auto v : e[u]) {
		if (v == f) continue;
		dfs(v, u);
	}
	r[u] = tot;
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		c1.modify(l[i], w[i]);
		c1.modify(r[i] + 1, -w[i]);
		c2.modify(l[i], w[i]);
	}
	for (int i = 1; i <= q; i++) {
		int op; cin >> op;
		if (op == 1) {
			int x, y; cin >> x >> y;
			ll d = y - w[x];
			w[x] = y;
			c1.modify(l[x], d), c1.modify(r[x] + 1, -d);
			c2.modify(l[x], d);
		} else {
			int x; cin >> x;
			cout << c2.query(r[x]) - c2.query(l[x] - 1) << " " << c1.query(l[x]) << '\n';
		}
	}
}
int main() {
	ios::sync_with_stdio(false),cin.tie(nullptr);
	solve();
	return 0;
}