#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5010, M = 500010, mod = 80112002;
int mp[M], n, m, f[N];
vector<int> t[N], rt[N], arr;
int cu[N], ru[N];
bool st[N];
void topsort() {
	queue<int> q;
	for(int i = 1; i <= n; i ++)
		if(!ru[i]) q.push(i), f[i] = 1, st[i] = 1;
	while(q.size()) {
		auto x = q.front(); q.pop();
		st[x] = true;
		arr.push_back(x);
		for(auto c : t[x])
			if(!st[c] && !(-- ru[c])) q.push(c);
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int a, b; cin >> a >> b;
		t[b].push_back(a);
		rt[a].push_back(b);
		cu[b] ++, ru[a] ++;
	}
	topsort();
	for(int i = 0; i < arr.size(); i ++) {
		int x = arr[i];
		for(int j = 0; j < rt[x].size(); j ++) {
			f[x] = (f[x] + f[rt[x][j]]) % mod;
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i ++)
		if(t[i].size() == 0) res += f[i];
	cout << res << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}