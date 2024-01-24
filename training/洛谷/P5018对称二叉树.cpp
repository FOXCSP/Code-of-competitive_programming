#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1000010;
const ll mod = 19999797979793;
int l[N], r[N], n, tot, a[N], w[N];
int ans = 0;
ll hasl[N], hasr[N], base = 1999997;
ll Hasl[N], Hasr[N];
int Has(int p) {
	int s = 0;
	while (p) {
		s = (s * base + p % 10) % mod;
		p /= 10;
	}
	return s;
}

int sz[N];
void dfs(int u) {
	if (l[u] != -1) dfs(l[u]);
	if (r[u] != -1) dfs(r[u]);
	sz[u] = sz[l[u]] + sz[r[u]] + 1;
	int lh = sz[l[u]], rh = sz[r[u]];
	if (lh == rh && hasl[l[u]] == hasr[r[u]] && Hasl[l[u]] == Hasr[r[u]]) {
		ans = max(ans, sz[u]);
	}
	hasl[u] = (hasl[l[u]] * base + w[u] * base + hasl[r[u]] * base) % mod;
	Hasl[u] = (Hasl[l[u]] * base + w[u] * base + Hasl[r[u]] * base) % mod;

	hasr[u] = (hasr[r[u]] * base + w[u] * base + hasr[l[u]] * base) % mod;
	Hasr[u] = (Hasr[r[u]] * base + w[u] * base + Hasr[l[u]] * base) % mod;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &l[i], &r[i]);		
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}