#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define fi first
#define se second
#define pb push_back
#define SZ(a) a.size()
#define rep(i, l, r) for(int i = l; i <= r; i ++)
#define lep(i, r, l) for(int i = r; i >= l; i --)
// #define int long long
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 110, M = 210;

int h[N], w[M], ne[M], e[M], idx;
int n, m, f[N][N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa) {
	for(int i = h[u]; i != -1; i = ne[i]) {
		int son = e[i];
		if(son != fa) {
			dfs(son, u);
			lep(j, m, 0) { // 循环体积
				rep(k, 0, j - 1) {
					f[u][j] = max(f[u][j], f[u][j - k - 1] + f[son][k] + w[i]);
				}
			}
		}
	}
}


void solve() {
	memset(h, -1, sizeof h);
	cin >> n >> m;
	rep(i, 1, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dfs(1, -1);
	cout << f[1][m] << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}