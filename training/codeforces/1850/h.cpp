#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define pb push_back
#define P __int128
#define se second
#define fi first
using namespace std;
using ll = long long;

const int N = 200010;
vector<pair<int, int>> adj[N];
int n, m;
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, -w});
	}
	
	vector<ll> d(n + 1, -1e18);
	bool f = 1;
	auto bfs = [&](int x) {
		queue<pair<int, ll>> que;
		que.push({x, 0});
		while (!que.empty()) {
			auto [u, dis] = que.front(); que.pop();
			for (auto [v, w] : adj[u]) {
				if (v == u) continue;
				if (d[v] == -1e18) d[v] = dis + w, que.push({v, d[v]});
				else if (d[v] != dis + w) {
						f = false;
						return ;
					}
				}
			}
	};
	for (int i = 1; i <= n &&f; i++) {
		if (d[i] == -1e18) bfs(i);
	}
	cout << (f ? "YES" : "NO") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int _ = 1;
	cin >> _;
	for (; _--; ) {
		solve();
	}
	return 0;
}
