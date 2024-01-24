#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int p[N], n, m, ans, s[N];
int find(int x) {
	return x == p[x] ? p[x] : p[x] = find(p[x]);
}

struct node {
	int d, x, y;
	bool operator < (const node & B) const {
		return d < B.d;
	}
};

vector<node> e;
void kruskal() {
	sort(e.begin(), e.end());
	for(int i = 1; i <= n; i ++) p[i] = i, s[i] = 1;
	for(auto v : e) {
		int px = find(v.x), py = find(v.y);
		if(px != py) {
			ans += (v.d + 1) * (s[px] * s[py] - 1);
			p[px] = py;
			s[py] += s[px];
		}
	}
} 

void solve() {
	cin >> n;
	ans = 0;
	e.clear();
	for(int i = 1; i < n; i ++) {
		int a, b, c; cin >> a >> b >> c;
		e.push_back({c, a, b});
	}
	kruskal();
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin >> _; while(_ --) solve();
	return 0;
}