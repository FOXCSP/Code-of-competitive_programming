#include <bits/stdc++.h>

using namespace std;

const int N = 300010, M = N * 2;
int fa[N][20], n, m;
int a[N], dep[N];

bool st[N];
int h[N], e[M], ne[M], idx;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int father, int depth) {
	dep[u] = depth, st[u] = true, fa[u][0] = father;
	for(int i = 1; i <= 19; i ++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for(int i = h[u]; i != -1; i = ne[i]) if(!st[e[i]]) dfs(e[i], u, depth + 1);
}

int LCA(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int k = 19; k >= 0; k --) if(dep[fa[a][k]] >= dep[b]) 
		a = fa[a][k];
	if(a == b) return a;
	for(int k = 19; k >= 0; k --) if(fa[a][k] != fa[b][k]) 
		a = fa[a][k], b = fa[b][k];
	return fa[a][0];
}

int num[N];
void calc(int u, int father) {
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(j != father) calc(j, u), num[u] += num[j];
	}
}

void solve() {
	int k;
	cin >> n >> k;
	memset(h, -1, sizeof h);
	for(int i = 1; i < n; i ++) {
		int a, b; cin >> a >> b;
		add(a, b); add(b, a);
	}
	dfs(1, 0, 1);
	for(int i = 1;i <= k; i ++) {
		int u, v;
		cin >> u >> v;
		int t = LCA(u, v);
		num[u] += 1, num[v] += 1;
		num[fa[t][0]] -= 2;
		num[t] -= 1, num[fa[t][0]] += 1;
	}
	calc(1, 0);
	for(int i = 2; i <= n; i ++) num[a[i]] --;
	cout << *max_element(num + 1, num + n + 1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}