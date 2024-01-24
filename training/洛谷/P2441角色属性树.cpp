#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int h[N], e[N], ne[N], idx, a[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int dfs(int fa, int now) {
	if(fa != now && __gcd(a[fa], a[now]) > 1) return fa;
	for(int i = h[fa]; i != -1; i = ne[i]) {
		int t = dfs(e[i], now);
		if(t) return t;
	}
	return 0;
}

void solve() {
	int n, k;
	cin >> n >> k;
	memset(h, -1, sizeof h);
	for(int i = 1;i <= n;i ++ )  cin >> a[i];
	for(int i = 1;i < n; i ++) {
		int x, y; cin >> x >> y;
		add(y, x);
	}
	while(k --) {
		int op, u;
		cin >> op >> u;
		if(op == 1) {
			int t = dfs(u, u);
			if(t) cout << t << '\n';
			else cout << "-1\n";
		}
		else cin >> a[u];
	}
}


int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}