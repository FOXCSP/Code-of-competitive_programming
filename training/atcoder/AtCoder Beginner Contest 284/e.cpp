#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = 400010;
vector<int> e[M];
int n, m, dist[N], ans = 0;
int st[N];
void dfs(int u) {
    ans++;
    if (ans >= 1e6) {
        cout << ans << '\n';
        exit(0);
    }
    st[u] = 1;
    for (auto v : e[u]) {
        if (st[v] == 0) dfs(v);
    }
    st[u] = 0;
}

void solve() {
    scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
        scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
    dfs(1);
    cout << ans << '\n';
}

int main() {
	solve();
	return 0;
}