#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
#define all(T) T.begin(), T.end() 
using namespace std;
typedef long long ll;

const int N = 200010;
const ll mod = 998244353;

struct node {
	int id, x, y;
};
vector<node> e[N];
int n, m, dg[N];
int x[N], y[N];
set<int> S;
queue<int> que;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		e[a].pb(node{b, x, y});
		e[b].pb(node{a, -x, -y}); 
	}
	for (int i = 1; i <= n; i++)
		x[i] = y[i] = 2e18;
	x[1] = y[1] = 0;
	que.push(1);
	while (!que.empty()) {
		auto t = que.front(); que.pop();
		for (auto v : e[t]) {
			if (x[v.id] != 2e18) continue;
			if (x[t] != 2e18) {
				x[v.id] = x[t] + v.x;
				y[v.id] = y[t] + v.y;
				que.push(v.id); 
			} else {
				S.insert(t);
			}
		}
		if (que.empty() && SZ(S)) {
			for (auto it = S.begin(); it != S.end(); it = next(it)) {
				if (x[*it] != 2e18) {
					que.push(*it);
					S.erase(it);
				} 
			}
		}
	}
	for (int i = 1; i<= n; i++) {
		if (x[i] == 2e18) cout << "undecidable\n";
		else cout << x[i] << " " <<y[i] << '\n';
	}
	return 0;
}
