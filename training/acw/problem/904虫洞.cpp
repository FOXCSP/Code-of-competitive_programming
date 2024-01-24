 #include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 100010;

int h[N], e[M], ne[M], w[M], idx;
int dist[N], n, m, cnt[N];
bool st[N];
void init() {
	memset(h, -1, sizeof h);
	memset(st, false, sizeof st);
	memset(dist, 0, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	idx = 0;
}

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool spfa() {
	queue<int> q;
	for(int i = 1; i <= n; i ++ ) {
		q.push(i);
		st[i] = true;
	}
	while(q.size()) {
		auto t = q.front();
		q.pop();
		st[t] = false;

		for(int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t] + w[i]) {
				cnt[j] = cnt[t] + 1;
				dist[j] = dist[t] + w[i];
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
	init();
	int m1, m2; cin >> n >> m1 >> m2;
	while(m1 --) {
		int a, b, c; cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}

	while(m2 --) {
		int a, b, c; cin >> a >> b >> c;
		add(b, a, -c);
	}

	if(spfa()) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin >> _; while(_ --) solve();
	return 0;
}