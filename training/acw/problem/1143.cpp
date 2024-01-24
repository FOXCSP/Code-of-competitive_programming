#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
int p[N];
struct edge {
	int d, x, y;
	bool operator < (const edge & B) const {
		return d < B.d;
	}
};

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int n, m, ans;

vector<edge> e;

void kruskra() {
	sort(e.begin(), e.end());
	for(auto v : e) {
		int px = find(v.x), py = find(v.y);
		if(px != py) {
			p[px] = py;
			ans += v.d;
		}
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n;i ++) p[i] = i;
	for(int i = 1;i <= m;i ++) {
		int op, u ,v, w;
		cin >> op >> u >> v >> w;
		if(op == 1) {
			int pu = find(u), pv = find(v);
			if(pu != pv) {
				p[pu] = pv;
			}
			ans += w;
		}
		else e.push_back({w, u, v});
	}
	kruskra();
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0;
}