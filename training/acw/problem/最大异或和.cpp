#include <bits/stdc++.h>

using namespace std;

const int N = 600010, M = N * 26;

int tr[M][2], max_id[M];
int n, m;
int root[N], idx, s[N];

void insert(int i, int k, int p, int q) { // 第i个串, p是q的上一个版本, k表示当前插到二进制的第k位
	if (k < 0) {
		max_id[q] = i;
		return ;
	}
	int v = s[i] >> k & 1;
	if (p) tr[q][v ^ 1] = tr[p][v ^ 1];
	tr[q][v] = ++idx;
	insert(i, k - 1, tr[p][v], tr[q][v]);
	max_id[q] = max(max_id[tr[q][0]], max_id[tr[q][1]]);
}

int query(int l, int r, int C) {
	int p = root[r]; // 在第r个版本上搜
	for (int i = 23; i >= 0; i--) {
		int v = C >> i & 1;
		if (max_id[tr[p][v ^ 1]] >= l) p = tr[p][v ^ 1];
		else p = tr[p][v];
	}
	return C ^ s[max_id[p]];
}


void solve() {
	cin >> n >> m;
	root[0] = ++idx;
	max_id[0] = -1;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		s[i] = s[i - 1] ^ x;
		root[i] = ++idx;
		insert(i, 23, root[i - 1], root[i]);
	}
	while (m--) {
		string op;
		cin >> op;
		if (op == "A") {
			int x; cin >> x;
			n++;
			s[n] = s[n - 1] ^ x;
			root[n] = ++idx;
			insert(n, 23, root[n - 1], root[n]);
		} else {
			int l, r, x; cin >> l >> r >> x;
			cout << query(l - 1, r - 1, s[n] ^ x) << '\n';
		}
	}

}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}