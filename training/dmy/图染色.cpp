#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = 500;

int n, m, q;
vector<int> e[N], bige[N];
int ans[N], col[N], big[N];
void solve() {
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		big[i] = (int)e[i].size() >= M;
	}
	for (int u = 1; u <= n; u++)
		for (auto v : e[u]) if (big[v]) 
			bige[u].push_back(v);

	for (int i = 0; i < q; i++) {
		int op, x;
		cin >> op >> x;
		if (op == 1) {
			col[x] ^= 1;
			for (auto v : bige[x])
				if (col[x]) ans[v] ++;
				else ans[v] --;
		} else {
			if (big[x]) cout << ans[x] << '\n';
			else {
				int cnt = 0;
				for (auto v : e[x]) cnt += col[v];
				cout << cnt << '\n';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}