#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = N * 2;

int h[N], e[M], ne[M], idx;

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int n, m, ans = N, f;
bool st[N];
vector<int> v;
int dfs(int u) { // dfs返回以u为根的子树大小
	int sum = 1, res = 0;
	st[u] = true;
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			int s = dfs(j);
			res = max(res, s); // res 保存 以u为根的子树大小
			sum += s;
		}
	}
	res = max(res, n - sum); // 最大的联通子树节点数
 	// ans = min(res, ans); // 最小的最大联通节点数
 	if(ans > res) {
 		ans = res;
 		v.clear();
 		v.push_back(u);
 	}
 	else if(ans == res) v.push_back(u);
	return sum;
}

int dist[N];
void dfs2(int u, int fa) {
	st[u] = true, dist[u] = dist[fa] + 1;
	for(int i = h[u]; i != -1; i = ne[i])
		if(!st[e[i]]) dfs2(e[i], u);
}

void solve() {
	cin >> n;
	memset(h, -1, sizeof h);
	for(int i = 1; i < n; i ++) {
		int a, b; cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1);
	ans = 0;
	sort(v.begin(), v.end());
	for(auto c : v) {
		memset(st, false, sizeof st);
		dist[0] = -1;
		dfs2(c, 0);
		int res = 0;
		for(int i = 1;i <= n; i ++) {
			res += dist[i];
		}
		if(ans < res) {
			ans = res, f = c;
		}
	}
	cout << f << ' ' << ans << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}