#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int n, m;
int g[N][N];
void solve() {
	cin >> n >> m;
	bool f = false;
	for(int i = 1; i <= m; i ++) {
		int a, b; cin >> a >> b;
		if(g[a][b] || a == b) f = true;
		g[a][b] = g[b][a] = 1;
	}
	if(f) cout << "No\n";
	else cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}