#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

const int N = 100010;
int idg[N];
vector<int> e[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		idg[u]++;
		idg[v]++;
		e[u].pb(v);
		e[v].pb(u);
	}
	
	queue<int> que;
	for (int i = 1; i <= n; i++)
		if (idg[i] == 1)
			que.push(i);
	map<int, int> mp;
	auto b = 1;
	while (que.size()) {
		auto x = que.front(); que.pop();
		mp[x]++;
		for (auto v : e[x]) {
			if ((--idg[v]) == 1)
				que.push(v);
		}
	}
	for (int i = 1; i <= n; i++)
		if (mp.count(i) == 0)
			cout << i << " ";
	cout << '\n';
	return 0;
} 
