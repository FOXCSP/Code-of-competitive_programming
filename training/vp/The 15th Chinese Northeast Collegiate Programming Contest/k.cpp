#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
// head

const int N = 200010, M = 200010;
int n, m, q;
ll sz[N];
ll cur, ans[N];
int p[N];
int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]); 
}
void merge(int x, int y) {
	int px = find(x);
	int py = find(y);
	if (px != py) {
		p[py] = px;
		cur -= (sz[py] * (sz[py] - 1)) / 2;
		cur -= (sz[px] * (sz[px] - 1)) / 2;
		sz[px] += sz[py];
		cur += (sz[px] * (sz[px] - 1)) / 2;
	}
}

void solve(int CaseT) {
	cin >> n >> m >> q;
	memset(ans, 0, sizeof ans);
	for (int i = 1; i <= n; i++) 
		p[i] = i, sz[i] = 1;
	cur = 0;
	vector<array<int, 3>> eg;
	vector<int> vx;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		eg.pb({w, u, v});
		vx.pb(w);
	}
	sort(all(eg));
	sort(all(vx));
	vx.erase(unique(all(vx)), vx.end());
	
	for (int i = m - 1; i >= 0; i--) {
		auto [w, u, v] = eg[i];
		merge(u, v);
		int p = lower_bound(all(vx), w) - vx.begin() + 1;
		ans[p] = cur;
	}

	for (; q--; ) {
		int w;
		cin >> w;
		int p = lower_bound(all(vx), w) - vx.begin() + 1;
		cout << ans[p] << '\n'; 
	}

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}

/*
2
5 5 3
1 2 2
2 3 3
3 4 1
4 5 1
5 1 3
3
2
1
5 5 3
1 2 2
2 3 3
3 4 1
4 5 1
5 1 3
3
2
1

1
5 5 3
1 2 2
2 3 3
3 4 1
4 5 1
5 1 3
3
2
1

*/
