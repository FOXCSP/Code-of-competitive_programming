#include <bits/stdc++.h>

using namespace std;
const int N = 5000010;

int dep[N], tdep[N], n, m;
int f1[N], f2[N]; 
// f1[u], 表示u儿子dep最大的儿子, f2[u],表示u儿子dep次大的儿子
int ans[N], mxd;
vector<int> e[N];

int read() {
	int s = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * f;
}

void print(int x) {
	if (x >= 10) 
		print(x / 10);
	putchar(x % 10 + '0');
	return ;
}

int dfs1(int u, int d) {
	dep[u] = tdep[u] = d;
	mxd = max(mxd, d);
	for (auto v : e[u]) {
		dep[u] = max(dep[u], dfs1(v, d + 1));
		if (dep[v] > dep[f1[u]]) {
			f2[u] = f1[u];
			f1[u] = v;
		} else if (dep[v] > dep[f2[u]]) {
			f2[u] = v;
		}
		// printf("xxx %d %d\n", v, dep[v]);
	}
	return dep[u];
}

// 对于 u 如果 f1[u] >= k && f2[u] < k 则存在一个儿子可以作为第k层的LCA
int dfs2(int u, int d) {
	// printf("xxx %d\n", u);
	if (dep[f2[u]] >= d) return u;
	if (tdep[u] == d) return u;
	return dfs2(f1[u], d);
}

int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; i++) {
		int x = read();
		e[x].push_back(i);
	}
	dfs1(1, 1);
	// for (int i = 1; i <= n; i++) {
	// 	printf("dep: %d %d\n",i, dep[i]);
	// }
	ans[1] = 1;
	for (int i = 2; i <= mxd; i++) {
		ans[i] = dfs2(ans[i - 1], i);
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d %d\n", f1[i], f2[i]);
	// }
	// puts("");
	for (int i = 1; i <= m; i++) {
		int x = read();
		print(ans[x]);
		puts("");
	}
	return 0;
}