#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
int mx[N][20], n, a[N], m;
int mn[N][20];

void init() {
	memset(mn, 0x3f, sizeof mn);
	for(int i = 1; i <= n; i ++) mx[i][0] = mn[i][0] = a[i];
	int t = log(n)/log(2) + 1;
	for(int j = 1; j < t; j ++)
		for(int i = 1; i <= n - (1 << j) + 1; i ++) {
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
		}
}

int querymx(int l, int r) {
	int k = log(r - l + 1) / log(2);
	return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}

int querymn(int l, int r) {
	int k = log(r - l + 1) / log(2);
	return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}



void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	init();
	while(m --) {
		int l, r; cin >> l >> r;
		cout << querymx(l, r) - querymn(l, r) << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}