#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 500010;
int h[N], ne[N], e[N], idx;
int res[N], n, fa[N], w[N];
char s[N];
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
	w[u] = w[fa[u]];
	if(s[u] == '(') w[u] = u;
	else if(w[u]) res[u] = 1 + res[fa[w[u]]], w[u] = w[fa[w[u]]];

	for(int i = h[u]; i != -1; i = ne[i]) dfs(e[i]);
}

void solve() {
	cin >> n >> s + 1;
	memset(h, -1, sizeof h);
	for(int i = 2; i <= n;i ++) {
		int x; cin >> x;
		fa[i] = x; add(x, i);
	}
	dfs(1);
	int ans = 0;
	for(int i = 1;i <= n; i ++) {
		// cout << res[i] << " \n"[i == n];
		res[i] += res[fa[i]];
		ans ^= (i * res[i]);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}