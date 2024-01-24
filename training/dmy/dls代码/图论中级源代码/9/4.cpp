#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int V = 201000;
const int E_ = 1001000;
template<typename T>
struct FlowGraph {
	int s, t, vtot;
	int head[V], etot;
	int dis[V], cur[V];
	struct edge {
		int v, nxt;
		T f;
	} e[E_ * 2];
	void addedge(int u,int v, T f){
		e[etot]= {v, head[u], f}; head[u] = etot++;
		e[etot]= {u, head[v], 0}; head[v] = etot++;
	}

	bool bfs() {
		for (int i = 1; i <= vtot; i++) {
			dis[i] = 0;
			cur[i] = head[i];
		}
		queue<int> q;
		q.push(s); dis[s] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = head[u]; ~i; i = e[i].nxt) {
				if (e[i].f && !dis[e[i].v]) {
					int v = e[i].v;
					dis[v] = dis[u] + 1;
					if (v == t) return true;
					q.push(v);
				}
			}
		}
		return false;
	}

	T dfs(int u, T m) {
		if (u == t) return m;
		T flow = 0;
		for (int i = cur[u]; ~i; cur[u] = i = e[i].nxt)
			if (e[i].f && dis[e[i].v] == dis[u] + 1) {
				T f = dfs(e[i].v, min(m, e[i].f));
				e[i].f -= f;
				e[i ^ 1].f += f;
				m -= f;
				flow += f;
				if (!m) break;
			}
		if (!flow) dis[u] = -1;
		return flow;
	}
	T dinic(){
		T flow=0;
		while (bfs()) flow += dfs(s, numeric_limits<T>::max());
		return flow;
	}
	void init(int s_, int t_, int vtot_) {
		s = s_;
		t = t_;
		vtot = vtot_;
		etot = 0;
		for (int i = 1; i <= vtot; i++) head[i] = -1;
	}
};

FlowGraph<int> g;
int L, R, m;
array<int,3> E[V];
int mat[V];
vector<int> e[V];
bool vis[V];

int main() {
	scanf("%d%d%d", &L, &R, &m);
	int s = L + R + 1;
	int t = L + R + 2;
	g.init(s, t, t);
	for (int i = 1; i <= L; i++) {
		g.addedge(s, i, 1);
	}
	for (int i = 1; i <= R; i++) {
		g.addedge(i + L, t, 1);
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[i] = {u, v + L, g.etot};
		g.addedge(u, v + L, 1);
	}
	g.dinic();
	for (int i = 1; i <= m; i++) {
		if (g.e[E[i][2]].f == 0) {
			mat[E[i][0]] = E[i][1];
			mat[E[i][1]] = E[i][0];
		}
	}
	for (int i = 1; i <= L + R; i++)
		e[i].clear();
	for (int i = 1; i <= m; i++) {
		auto [u, v, id] = E[i];
		if (g.e[id].f == 0) {
			e[v].push_back(u);
		} else {
			e[u].push_back(v);
		}
	}
	memset(vis, 0, sizeof(vis));
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (auto v : e[u])
			if (!vis[v]) dfs(v);
	};
	for (int i = 1; i <= L; i++) if (mat[i] == 0) {
		dfs(i);
	}
	for (int i = 1; i <= L; i++) if (!vis[i]) {
		printf("%d\n" ,i);
	}

	for (int i = 1; i <= L + R; i++)
		e[i].clear();
	for (int i = 1; i <= m; i++) {
		auto [u, v, id] = E[i];
		if (g.e[id].f == 0) {
			e[u].push_back(v);
		} else {
			e[v].push_back(u);
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = L + 1; i <= L + R; i++) if (mat[i] == 0) {
		dfs(i);
	}
	for (int i = L + 1; i <= L + R; i++) if (!vis[i]) {
		printf("%d\n" ,i - L);
	}

}