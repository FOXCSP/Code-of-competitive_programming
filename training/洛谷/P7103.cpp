#include <bits/stdc++.h>

using namespace std;

// dfs搜出最大f(u), 次大f(w)
const int N = 5000010;
int n, m;
int h[N], e[N], ne[N], idx;
void add(int a,int b,int c) {e[idx] = b, ne[idx] = h[a]; h[a] = idx ++;}
int f[N];
void dfs1(int u, int dep) {
	for(int i = h[u]; i != -1; i = ne[i]) {
		int son = e[i];
		
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		int x; cin >> x;
		if(i - 1) add(x, i);
	}
	while(m --) {
		int k; cin >> k;
		// 
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}