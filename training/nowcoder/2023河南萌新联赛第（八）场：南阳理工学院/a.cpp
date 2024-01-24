#include <bits/stdc++.h>
#define int long long
#define se second
#define fi first
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;
typedef long long ll;

const int N = 1000010;
int n, m, k, w;
int a[N], b[N], p[N], res[N];
int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k >> w;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (b[u] == 1 && 1 == b[v]) {
			int pu = find(u);
			int pv = find(v);
			if (pu != pv) {
				a[pu] += a[pv];
				p[pv] = pu;
			}
		}
	}
	vector<int> vx;
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		if (mp.count(find(i)) == 0 && b[find(i)] == 1) {
			vx.pb(a[find(i)]);
			mp[find(i)]++;
		}
	}
	sort(all(vx));
	int ans = 0;
	for (int i = SZ(vx) - 1; i >= 0 && k > 0; i--, k--) {
		ans += vx[i];
	}
	cout << ans << '\n';

	return 0;
}