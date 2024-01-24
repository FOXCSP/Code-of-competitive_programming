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

vec<P(int)> e[N];
int n, m;
int dep[N], fat[N], fa[N][20], d[N];

void dfs(int u, int f, int t) {
	dep[u] = dep[f] + 1; 
	fat[u] = f;
	d[u] = d[f] + t;
	fa[u][0] = f;
	for (int k = 1; k < 20; k++) {
		fa[u][k] = fa[fa[u][k-1]][k-1];
	}
	for (int i = 0; i < SZ(e[u]); i++) {
		int v = e[u][i].fi;
		int w = e[u][i].se;
		if (v == f) continue;
		dfs(v, u, w);
	}
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int i = 19; i >= 0; i--) {
		if (dep[fa[a][i]] >= dep[b]) {
			a = fa[a][i];
		}
	}
	if (a == b) return a;
	for (int i = 19; i >= 0; i--) {
		if (fa[a][i] != fa[b][i]) {
			a = fa[a][i];
			b = fa[b][i];
		}
	}
	return fa[a][0];
}


void solve (int Case) {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		e[u].pb({v, t});
		e[v].pb({u, t});
	}
	dfs(1, 0, 0);
//	for (int i = 1; i <= n; i++) {
//		cout << i << " " << dep[i] << " " << d[i] << " " << fat[i] << '\n';
//	}
//	for (int i = 1; i < n; i++) {
//		cout << i << " " << i + 1 << " " << lca(i, i + 1) << '\n';
//	}
	
	int ans = 0;
	vec<int> ak(k+1,0);
	vec<int> gx(k+1,0);
	for (int i = 1; i <= k; i++) {
		cin >> ak[i];
		if (i > 1) {
			int t = lca(ak[i-1], ak[i]);
			ll dis = d[ak[i-1]] + d[ak[i]] - 2ll * d[t];
//			cout << dis << " ";
			gx[i] = dis;
			ans += dis;
		}
	}
//	cout << '\n';
	
	for (int i = 1; i <= k; i++) {
		int res = 0;
		if (i == 1 || i == k) {
			if (i == 1) cout << (ans - gx[i + 1]) <<  " ";
			else cout << (ans - gx[i]) << " ";
		} else {
			res = gx[i] + gx[i + 1];
			int t = lca(ak[i-1], ak[i+1]);
			int dis = d[ak[i-1]] + d[ak[i+1]] - 2ll * d[t];
			cout << (ans - res + dis) << " ";
		}
	}
}

/*

6 4
1 2 1
1 3 1
3 4 2
3 5 2
4 6 3
2 6 5 1
 */


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
	for (int i=1; i<=_;i++) {
		solve(i);
	}
	return 0;
}
