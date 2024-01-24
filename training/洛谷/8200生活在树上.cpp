#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 500010, M = 2 * N;
int h[N], ne[M], e[M], idx;
int n, m;
ull xo[N];
ull w[M];
void add(int a, int b, ull c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa, ull o) {
	xo[u] = o;
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(j != fa) dfs(j, u, o ^ w[i]);
	}
}

void solve() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	int a, b;
	ull k;
	for(int i = 1;i < n; i ++ ) {
		cin >> a >> b >> k;
		add(a, b, k), add(b, a, k);
	}
	dfs(1, 0, 0);
	while(m --) {
		cin >> a >> b >> k;
		if((xo[a] ^ xo[b]) == k) cout << "Yes\n";
		else cout << "No\n";
 	}
}

signed main () {
	ios::sync_with_stdio(false),cin.tie(nullptr);
	solve();
	return 0;
}