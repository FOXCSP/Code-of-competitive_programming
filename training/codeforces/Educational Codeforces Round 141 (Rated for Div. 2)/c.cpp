#include <bits/stdc++.h>

using namespace std;

const int N=500010;
int n, m, all, a[N], pos[N];
struct name {
	int v, id;
	bool operator < (const name& B) const {
		return v < B.v;
	}
} st[N];
void solve() {
	cin >> n >> m;
	all = 0;
	for (int i = 1; i <= n; i++) st[i].v = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st[i].v = a[i];
		st[i].id = i;
	}
	sort(st + 1, st + n + 1);
	for (int i = 1; i <= n; i++) {
		st[i].v += st[i - 1].v;
		if (st[i].v <= m) all++;
		pos[st[i].id] = i;
	}
	int ans = 1, p = min(n, all + 1);
	if (a[p] + st[all - 1].v <= m) cout << (n - p + 1) << '\n';
	else cout << (n - p + 2) << '\n';
}

int main() {
	int _; cin >> _;
	while (_--) solve();
	return 0;
}