#include <bits/stdc++.h>


using namespace std;

const int N = 100010;
int p[N], n, m, ans = 0;

struct node {
	int d, x, y;
	bool operator < (const node & B) const {
		return d < B.d;
	}
};

int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
vector<node> e;
vector<pair<int,int>> point;
int get(pair<int,int> a, pair<int,int> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
void kruskal() {
	sort(e.begin(), e.end());
	for(int i = 1; i <= n; i ++) p[i] = i;
	int cnt = n;
	for(auto v : e) {
		int px = find(v.x), py = find(v.y);
		if(px != py) {
			p[py] = px;
			ans += v.d;
			cnt --;
		}
	}
	if(cnt > 1) ans = -1;
}
void solve () {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		int a, b; cin >> a >> b;
		point.push_back({a, b});
	}
	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++) {
				int t = get(point[i], point[j]);
				if(t >= m) e.push_back({t, i, j});
			}
	kruskal();
	cout << ans << '\n';
}


int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}