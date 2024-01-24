#include <bits/stdc++.h>
#define fi first
#define se second
#define lp (p<<1)
#define rp (p<<1|1)
#define pb emplace_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setop(T) cout<<fixed<<setprecision(T);
using namespace std;
using ll = long long;

const int N = 200010;
vector<int> e[N];
int col[N];
int n, m;
int vis[N];
int sz[N], eg[N];

void dfs(int u, int c, int fa) {
	col[u] = c;
	vis[u] = 1;
	sz[c]++;
	for (auto v : e[u]) {
		if (vis[v]) {
			continue;
		}
		dfs(v, c, u);
		eg[u] += eg[v];
	}
}

void solve(int caseT) {
	cin >> n >> m;
	map<pair<int, int>, int> mp;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
		eg[u]++;
		eg[v]++;
	}
	int id = 1;
	for (int i = 1; i <= n; i++) {
		if (col[i]) continue;
		dfs(i, id++, 0);
	}
	for (int i = 1; i < id; i++) {
		if (eg[i] != sz[i] * 2) {
			cout << "No\n";
			return ;
		}
	}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _;
	_=1;	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}