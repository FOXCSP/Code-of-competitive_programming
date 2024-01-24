#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int c[N];
int n, a[N], le[N], ri[N] ,s[N];
void add(int x, int y) {
	while(x <= N) {
		c[x] += y;
		x += x & -x;
	}
}

int query(int x) {
	int res = 0;
	while(x) {
		res += c[x];
		x -= x & -x;
	}
	return res;
}
void solve() {
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		le[i] = query(a[i] - 1);
		add(a[i], 1);
	}

	memset(c, 0, sizeof c);

	for(int i = n; i;i --) {
		ri[i] = query(1e5) - query(a[i]);
		add(a[i], 1);
	}
	for(int i = 1;i <= n;i ++) cout << le[i] << " ";
	cout << '\n';
	for(int i = 1;i <= n;i ++) cout << ri[i] << " ";
	cout << '\n';
	long long ans = 0;
	for(int i = 1;i <= n;i ++) {
		ans += (le[i] * ri[i]);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0;
}