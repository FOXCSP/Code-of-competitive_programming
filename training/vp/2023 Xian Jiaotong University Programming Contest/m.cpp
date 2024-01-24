#include <bits/stdc++.h>
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
typedef double db;
// head

const int N = 100010;
int tmp[N], n, m, dep[N], a[N], mint[N], maxt[N], c[N];
vector<int> e[N];

void dfs(int u, int f) {
	mint[u] = maxt[u] = tmp[u];
	for (auto v : e[u]) {
		if (v != f) {
			dfs(v, u);
			mint[u] = min(mint[u], mint[v]);
			maxt[u] = max(maxt[u], maxt[v]);
		}
	}
}

void solve(int CaseT) {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		e[i].pb(x);
		e[x].pb(i);
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		tmp[a[i]] = i;
	}
	dfs(1, 0);
//	for (int i = 1; i <= n; i++) {
//		cout << mint[i] << " " << maxt[i] << " \n";
//	}
	for (int i = 1; i <= n; i++) {
		c[mint[i]]++;
		c[maxt[i]]--;
	}
	for (int i = 1; i <= n; i++)
		c[i] += c[i - 1];
	for (int i = 1; i <= n; i++) {
		cout << c[i] << " \n"[i == n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
//	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}
