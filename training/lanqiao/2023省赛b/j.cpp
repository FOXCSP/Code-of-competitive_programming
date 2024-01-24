#include <bits/stdc++.h>
#define int long long
#define vec vector
#define se second
#define fi first
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;

const int N = 100010;

vec<int> e[N];
int n, m;
int dep[N], fat[N], fa[N][20], d[N];
int sz1[N], sz2[N], col[N];
int tot, l[N], r[N];
void dfs(int u, int f) {
	dep[u] = dep[f] + 1;
	l[u] = ++tot;
	if (col[u] > 0) sz1[u] = col[u];
	if (col[u] < 0) sz2[u] = col[u];
	for (int i = 0; i < SZ(e[u]); i++) {
		int v = e[u][i];
		if (v == f) continue;
		dfs(v, u);
		sz1[u] += sz1[v];
		sz2[u] += sz2[v];
	}
	r[u] = tot;
}

bool check(int u, int v) {
	return (l[u] <= l[v] && r[u] >= r[v]);
}

void solve (int Case) {
	int n, m;
	cin >> n >> m;
	vec<P(int)> eg;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
		eg.pb({u, v});
	}
	vec<P(int)> vx;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		vx.pb({u, v});
	}
	dfs(1, 0);
//	for (int i = 1; i <= n; i++) {
//		cout << l[i] << " " << r[i] << '\n';
//	}
	
	for (int i = SZ(eg) - 1; i >= 0; i--) {
		int u = eg[i].fi;
		int v = eg[i].se;
		if (dep[u] < dep[v]) swap(u, v);
		bool f = 1;
		for (int j = 0; j < SZ(vx); j++) {
			if (!(check(u, vx[j].fi) ^ check(u, vx[j].se))) {
				f = 0;
//				cout << u << " " << vx[j].fi << " " << vx[j].se << '\n';
				break;
			}
		}
		if (f) {
			cout << (i + 1) << '\n';
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int _;
	_=1;
	for (int i=1; i<=_;i++) {
		solve(i);
	}
	return 0;
}
