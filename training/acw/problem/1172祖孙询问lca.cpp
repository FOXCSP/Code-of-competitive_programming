#include <bits/stdc++.h>

using namespace std;

const int N = 40010, M = 20;
int f[N][M], dep[N] = {0};
int h[N], e[N<<1], ne[N<<1], idx;
int n, m;
void add(int a,int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool st[N];
void dfs(int u, int fa, int depth) {
	f[u][0] = fa, dep[u] = depth;
	// cout << u << " " << dep[u] << " xxxx\n";
	st[u] = 1;
	for(int i = 1; i <= 15; i ++) f[u][i] = f[f[u][i - 1]][i - 1];
	for(int i = h[u]; i != -1; i = ne[i]) {
		if(!st[e[i]])	dfs(e[i], u, depth + 1);
	}
}

int LCA(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int k = 15; k >= 0; k --) if(dep[f[a][k]] >= dep[b]) 	a = f[a][k];
	if(a == b) return a;
	for(int k = 15; k >= 0; k --) if(f[a][k] != f[b][k])	a = f[a][k], b = f[b][k];
	return f[a][0];
}

void solve() {
	memset(h, -1, sizeof h);
	cin >> n;
	int root;
	for(int i = 1;i <= n; i ++) {
		int a, b; cin >> a >> b;
		if(b == -1) root = a;
		else add(a, b), add(b, a);
	}
	cin >> m;
	dfs(root, 0, 1);
	// for(int i = 1;i <= n; i ++) cout << dep[i] << " \n"[i == n];
	while(m --) {
		int a, b; cin >> a >> b;
		int t = LCA(a, b);
		if(t == a) cout << 1 << '\n';
		else if(t == b) cout << 2 << '\n';
		else cout << 0 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}