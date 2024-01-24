#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int N = 1010, M = 20010;
int h[N], w[M], e[M], ne[M], idx;
int dist[N];
int n, m, s;
bool st[N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> heap;
	heap.push({0, s});
	cout << "xxx\n";
	while(heap.size()) {
		auto t = heap.top(); heap.pop();
		int ver = t.second, d = t.first;
		if(st[ver]) continue;
		st[ver] = 1;
		for(int i = h[ver]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] > d + w[i]) {
				dist[j] = d + w[i];
				heap.push({dist[j], j});
			}
		}
		cout << heap.size() << "\n";
	}
}

void solve() {
	while(cin >> n >> m >> s) {
		memset(h, -1, sizeof h);
		for(int i = 1;i <= m; i ++) {
			int a, b, c;
			cin >> a >> b >> c;
			add(b, a, c);
		}
		dijkstra();
		int t;
		cin >> t;
		int ans = 0x3f3f3f3f;
		for(int i = 1; i <= t; i ++) {
			int x; cin >> x;
			ans = min(ans, dist[x]);
		}
		if(ans == 0x3f3f3f3f) cout << "-1\n";
		else cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}