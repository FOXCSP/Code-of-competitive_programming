#include <bits/stdc++.h>

using namespace std;

const int N = 210;

struct edge {
	int d, x, y;
	bool operator < (const edge & B) const {
		return d < B.d;
	}
};

vector<edge> e;
int n, m, p[N];
int sum = 0;
int find(int x) {
	return x == p[x] ? p[x] : p[x] = find(p[x]);
}

int kruskra() {
	int res = 0;
	sort(e.begin(), e.end());
	for(int i = 0;i <= n;i ++) p[i] = i;
	for(auto v : e) {
		int d = v.d, x = v.x, y = v.y;
		int px = find(x), py = find(y);
		if(px != py) {
			p[py] = px;
			res += d;
		}
	}
	return res;
}

void solve() {
	cin >> n >> m;
	for(int i = 1;i <= m;i ++ ) {
		int x, y, d;
		cin >> x >> y >> d;
		e.push_back({d, x, y});
		sum += d;
	}
	cout << sum - kruskra() << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0;
}