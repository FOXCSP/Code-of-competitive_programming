#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 5010;
int val[N], h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int n, m;
bool st[N];
double dist[N], eps = 1e-4;
int cnt[N];
bool spfa(double mid) {
	memset(st, false, sizeof st);
	memset(dist, 0, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	queue<int> q;
	for(int i = 1; i <= n; i ++) {
		q.push(i);
		st[i] = true; 
	}
	// cout << mid << '\n';
	while(q.size()) {
		int t = q.front(); q.pop();
		st[t] = false;
		for(int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			double x = 1.0 * val[t] - 1.0 * mid * w[i];
			if(dist[j] < dist[t] + x) {
				dist[j] = dist[t] + x;
				cnt[j] = cnt[t] + 1;
				if(cnt[j] >= n) return true;
				if(!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
}

void solve() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= n; i ++) cin >> val[i];
	for(int i = 1; i <= m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	double l = 0.0, r = 1000.0;	
	while(r - l > eps) {
		double mid = (l + r) / 2;
		if(spfa(mid)) l = mid; else r = mid;
	}
	printf("%.2f\n", l);
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}