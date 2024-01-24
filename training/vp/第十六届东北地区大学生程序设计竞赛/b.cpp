#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
// head

const int N = 100010;
int n, m, res;
vector<int> e[N];

vector<int> bfs(int u, int &rt) {
	queue<int> que;
	que.push(u);
	vector<int> d(n + 1, 0);
	while (que.size()) {
		auto t = que.front();
		que.pop();
		for (auto x : e[t]) {
			if (d[x] || x == u) continue;
			d[x] = d[t] + 1;
			que.push(x);
		}
	}
	rt = max_element(d.begin(), d.end()) - d.begin();
	return d;
}

vector<int> path, d;
int s, t;
bool dfs(int u, int f) {
	path.pb(u);
	if (u == t) {
		return true;
	}
	for (auto v : e[u]) {
		if (v == f)
			continue;
		if (dfs(v, u)) return true;
	}
	path.pop_back();
	return false;
}

int mxd[N], dep[N], dis[N];
void gd(int u, int f) {
	mxd[u] = d[u];
	for (auto v : e[u]) {
		if (v == f)
			continue;
		gd(v, u);
		mxd[u] = max(mxd[u], mxd[v]);
	}
}

void solve(int CaseT) {
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	bfs(1, s);
	d = bfs(s, t);
	dfs(s, 0);
	int id = (SZ(path) + 1) / 2;
	int root = path[id - 1];
	cout << root << " xxx\n";
	gd(root, 0);
	for (int i = 1; i <= n; i++)
		dis[i] = mxd[i] - d[i];
	for (int i = 1; i <= n; i++){
		cout << dis[i] << " \n"[i == n];
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
//	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}
