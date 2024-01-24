#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 200010;
const ll mod = 998244353;

vector<int> e[N];
int n, m;
int dg[N], st[N];
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		e[i].pb(x);
		dg[x]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!dg[i])
			q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		st[u] = 1;
		for (auto v : e[u]) {
			if (!(--dg[v]))
				q.push(v);
		}
	}

	function<void(int)> dfs = [&](int u) -> void {
		st[u] = 1;
		ans.pb(u);
		for (auto v : e[u]) {
			if (st[v]) continue;
			dfs(v);
		}
	};
	int p = 0;
	for (int i = 1; i <= n; i++)
		if (!st[i]) {
			dfs(i);
			break;
		}
	cout << ans.size() <<'\n';
	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}
