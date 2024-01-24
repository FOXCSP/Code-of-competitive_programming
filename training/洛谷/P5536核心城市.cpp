#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100010, M = 2 * N;

int h[N], e[M], ne[M], idx, ans;
void add(int a,int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx ++; }

int n, k;
int maxd[N], dep[N];
vector<pair<int,int>> dis;

bool st[N];
int dfs(int u, int fa) { // dfs返回最大的子树深度
	dep[u] = dep[fa] + 1, st[u] = true;
	int res = dep[u];
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			int s = dfs(j, u);
			res = max(s, res);
		}
	}
	maxd[u] = res;
	dis.push_back({maxd[u] - dep[u], u});
	return res;
}

map<int,int> mp;
int check(int id) {
	auto t = dis[id];
	int res = 0;
	for(int i = h[t.second]; i != -1; i = ne[i]) {
		int j = e[i];
		if(mp[j]) continue;
		res = max(res, maxd[j] - dep[j] + 1);
	}
	return res;
}
// 两次dfs求树上直径

int len, t1, t2, path[N];
void dfs1(int u, int fa) {
	st[u] = true;
	dep[u] = dep[fa] + 1;
	if(len < dep[u]) len = dep[u], t1 = u;
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(st[j]) continue;
		dfs1(j, u);
	}
}

void dfs2(int u, int fa) {
	dep[u] = dep[fa] + 1, st[u] = true;
	// cout << fa << " -> " << u << " " << dep[u] << '\n';
	if(len < dep[u] - 1) len = dep[u] - 1, t2 = u;
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(st[j]) continue;
		path[j] = u;
		dfs2(j, u);
	}
}

void init() {
	memset(st, false, sizeof st);
	memset(dep, 0, sizeof dep);
}

void solve() {
	cin >> n >> k;
	memset(h, -1, sizeof h);
	for(int i = 1; i < n; i ++) {
		int a, b; cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs1(1, 0);
	init();
	len = 0; 
	dfs2(t1, 0);
	// 找到中点
	int root = t2;
	for(int i = 1; i <= (dep[t2]) / 2; i ++) root = path[root];
	init();
	// cout << root << '\n';
	dfs(root, 0);
	sort(dis.begin(), dis.end(), greater<pair<int,int>>());
	cout << dis[k].first + 1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}