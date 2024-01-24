#include <bits/stdc++.h>

using namespace std;

const int N = 2010, M = 100010;
int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int n, m;
bool st[N];
double dist[N], eps = 1e-4;
int cnt[N], num;
map<string,int> mp;
bool spfa(double mid) {
	memset(st, false, sizeof st);
	memset(dist, 0, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	queue<int> q;
	for(int i = 1; i <= num; i ++) {
		q.push(i);
		st[i] = true; 
	}
	// cout << mid << '\n';
	while(q.size()) {
		int t = q.front(); q.pop();
		st[t] = false;
		for(int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			double x = 1.0 * w[i] - mid;
			if(dist[j] < dist[t] + x) {
				dist[j] = dist[t] + x;
				cnt[j] = cnt[t] + 1;
				if(cnt[j] >= num) return true;
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
	memset(h, -1, sizeof h);
	num = 0, idx = 0, mp.clear();
	for(int i = 1; i <= n; i ++) {
		string s; cin >> s;
		int len = s.size();
		string A = s.substr(len - 2, 2);
		string B = s.substr(0, 2);
		if(mp[A] == 0) mp[A] = ++ num;
		if(mp[B] == 0) mp[B] = ++ num;
		add(mp[A], mp[B], len);
	}
	double l = 0.0, r = 1001.0;	
	while(r - l > eps) {
		double mid = (l + r) / 2;
		if(spfa(mid)) l = mid; else r = mid;
	}
	if(l == 0.0 || l == 1001.0) printf("No solution\n");
	else printf("%.4f\n", l);
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	while(cin >> n) {
		if(n == 0) break;
		solve();
	}
	return 0;
}