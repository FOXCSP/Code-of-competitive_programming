#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200010;

int n, q;
int a[N];
vector<int> e[N];
template<class T>
struct BIT {
	T c[N];
	void modify(int x, int v) {
		for (; x <= n; x += x & -x) c[x] += v;
	}
	T query(int x) {
		T s = 0;
		for (; x; x -= x & -x) s += c[x];
		return s;
	}
};
BIT<ll> c;
int L[N], R[N], tot, root;
vector<pair<int, int>> son[N];
void dfs(int u, int fa) {
	L[u] = ++tot;
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs(v, u);
		son[u].push_back({L[v], R[v]});
	}
	R[u] = tot;
}

void solve() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		c.modify(L[i], a[i]);
	}
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			int d = y - a[x];
			a[x] = y;
			c.modify(L[x], d);
		} else if (op == 2) {
			int x;
			scanf("%d", &x);
			if (x == root) {
				printf("%lld\n", c.query(tot));
			} else if (L[x] < L[root] && R[root] <= R[x]) {
				auto seg = *prev(upper_bound(son[x].begin(), son[x].end(), 
					pair<int, int>{L[root], R[root]}));
				ll ans = c.query(tot);
				ans -= c.query(seg.second) - c.query(seg.first - 1);
				// printf("%d %d\n", seg.first, seg.second);
				printf("%lld\n", ans);
			} else {
				printf("%lld\n", c.query(R[x]) - c.query(L[x] - 1));
			}
		} else {
			scanf("%d", &root);
		}
	}
}

int main() {
	solve();
}