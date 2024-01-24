#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000010;
int n;
vector<int> e[N];
ll dep[N], sz[N];
ll dp[N];

ll dfs(int u, int f) {
	ll res = 1;
	dep[u] = dep[f] + 1;
	for (auto v : e[u]) {
		if (v == f) continue;
		res += dfs(v, u); 
	}
	return sz[u] = res;
}

void ans(int u, int f) {
	for (auto v : e[u]) {
		if (v == f) continue;
		dp[v] = dp[u] + n - 2ll * sz[v];
		ans(v, u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dep[0] = -1;
	dfs(1, 0);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += dep[i];
	}
	dp[1] = sum;	
	ans(1, 0);
	ll as = 0, id = 0;
	for (int i = 1; i <= n; i++) {
		if (as < dp[i]) {
			as = dp[i];
			id = i;
		}
	}
	printf("%lld\n", id);
	return 0;
}