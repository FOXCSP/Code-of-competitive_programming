#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1000010, mod = 998244353;

int T[N], n, a[N], c[N], ans;

void modify(int x, int v) {
	for (; x <= n; x += x & (-x)) c[x] += v;
}

int query(int x) {
	int s = 0;
	for (; x; x -= x & (-x)) s += c[x];
	return s;
}

void init() {
	T[0] = T[1] = 1;
	for (int i = 1; i <= n; i++) {
		T[i] = T[i - 1] * i % mod;
	}
}

void solve() {
	cin >> n;
	init();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		modify(a[i], 1);
		int t = query(a[i] - 1);
		ans = (ans + (a[i] - t - 1) * T[n - i] % mod) % mod;
	}
	cout << (ans + 1) % mod << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}