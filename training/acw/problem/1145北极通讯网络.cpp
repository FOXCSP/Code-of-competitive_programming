#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, m, p[N];
double ans[N];
struct node {
	double d;
	int x, y;
	bool operator < (const node & B) const {
		return d < B.d;
	}
};

double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int find(int x) {return x == p[x] ? p[x] : p[x] = find(p[x]);}

vector<node> e;

void kruskal() {
	sort(e.begin(), e.end());
	queue<double> q;
	int idx = 1;
	for(int i = 1; i <= n; i ++) p[i] = i;
	for(auto v : e) {
		int px = find(v.x), py = find(v.y);
		if(px != py) {
			p[py] = px;
			ans[idx ++] = v.d;
		}
	}
}

vector<pair<double, double>> point;
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		double x, y; cin >> x >> y;
		point.push_back({x, y});
	}
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(i != j) {
				auto &x = point[i];
				auto &y = point[j];
				e.push_back({dis(x.first, x.second, y.first, y.second), i, j});
			}
	kruskal();
	printf("%.2f\n", ans[n - m + 1]);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}