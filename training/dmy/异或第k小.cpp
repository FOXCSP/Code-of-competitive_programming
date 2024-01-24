#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

struct node {
	int son[2], sz;
	// 统计下没个节点的子树大小
} seg[N * 32];

int idx, root, n, m, a[N];

void insert(int x) {
	int p = root;
	for (int k = 30; k >= 0; k--) {
		seg[p].sz += 1;
		int u = (x >> k) & 1;
		if (!seg[p].son[u]) seg[p].son[u] = ++idx;
		p = seg[p].son[u];
	}
	seg[p].sz += 1;
}

int find(int x, int k) { // find the kmin
	int ans = 0;
	int p = root;
	for (int j = 30; j >= 0; j--) {
		int u = (x >> j) & 1;
		if (seg[seg[p].son[u]].sz >= k) {
			p = seg[p].son[u];
		} else {
			k -= seg[seg[p].son[u]].sz;
			ans ^= (1 << j);
			p = seg[p].son[!u];
		}
	}
	return ans;
}

void solve() {
	cin >> n >> m;
	root = ++idx;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		insert(a[i]);
	}
	for (int i = 1; i <= m; i++) {
		int x, k;
		cin >> x >> k;
		cout << find(x, k) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}