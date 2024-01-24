#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct node {
	int d, x, y;
	bool operator < (const node & B) const {
		return d < B.d;
	}
};

int n, p[N], ans;
int find(int x) {
	return x == p[x] ? p[x] : p[x] = find(p[x]);
}

vector<node> e;
void Kruskal() {
	sort(e.begin(), e.end());
	for(int i = 1; i <= n + n * n; i ++) p[i] = i;
	for(auto v : e) {
		int px = find(v.x), py = find(v.y);
		if(px != py) {
			p[py] = px;
			ans += v.d;
		}
	}
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		int x; cin >> x;
		e.push_back({x, i, n + 1}); // n + 1 为一个超级源点
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			int x; cin >> x;
			if(i != j) e.push_back({x, i, j});
		}
	}
	Kruskal();
	cout << ans << '\n'; 
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}