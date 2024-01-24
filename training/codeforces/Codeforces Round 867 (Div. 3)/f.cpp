#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
#define P(T) pair<T,T>
using namespace std;
typedef long long ll;
typedef long double lbd;
// head

const int N = 200010;
vec<int> e[N];
int k, c, n, m, dep[N], vis[N], len, fa[N];

vec<int> bfs(int x) {
	vec<int> d(n + 1, -1);
	queue<int> que;
	que.push(x);
	d[x] = 0;
	while (!que.empty()) {
		auto u = que.front(); 
		que.pop();
		for (auto v : e[u]) {
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				que.push(v); 
			}
		}
	}
	return d;
}

void solve(int CaseT) {
	cin >> n >> k >> c;
	for (int i = 1; i <= n; i++) {
		dep[i] = fa[i] = 0;
 	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u); 
	}
	auto dep = bfs(1);
	int s = max_element(all(dep)) - dep.begin();
	auto ds = bfs(s);
	int t = max_element(all(ds)) - ds.begin();
	auto dt = bfs(t);
	
	ll ans = -(1 << 30); 
	for (int i = 1; i <= n; i++) {
		ans = max(ans, 1ll * max(ds[i], dt[i]) * k - 1ll * dep[i] * c);
	}
	cout << ans << '\n';
	
	for (int i = 1; i <= n; i++) {
		e[i].clear();
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  _=1;
   cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}
