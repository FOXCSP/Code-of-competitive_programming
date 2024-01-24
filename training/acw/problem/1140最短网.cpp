#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int N = 110, inf = 0x3f3f3f3f;
int g[N][N], dist[N], n;
bool st[N];
int prim() {
	memset(dist, 0x3f, sizeof dist);
	int res = 0;
	for(int i = 0;i < n;i ++) {
		int t = -1;
		for(int j = 1; j <= n;j ++)
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		if(i && dist[t] == inf) return inf;
		if(i) res += dist[t];
		for(int j = 1;j <= n; j ++)
			dist[j] = min(dist[j], g[t][j]);
		st[t] = 1;
	}
	return res;
}

void solve() {
	cin >> n;
	for(int i = 1;i <= n; ++ i)
		for(int j = 1;j <= n; ++ j)
			cin >> g[i][j];
	cout << prim() << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0;
}