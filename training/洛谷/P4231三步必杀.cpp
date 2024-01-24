#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10000010;
ll read() {
	ll s = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		s = 1ll * s * 10 + c - '0';
		c = getchar();
	}
	return 1 * s * f;
}

ll a[N], b[N], c[N];
int n, m;
int main() {
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		ll l = read();
		ll r = read();
		ll s = read();
		ll e = read();
		ll d = (e - s) / (r - l);
		c[l+1] += d - s;
		c[l] += s;
		c[r+1] -= (e + d);
		c[r+2] += e;
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + c[i];
	}
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + b[i];
	}
	pair<ll, ll> ans = {0ll, 0ll};
	for (int i = 1; i <= n; i++) {
		ans.first ^= a[i];
		ans.second = max(a[i], ans.second);
	}
	printf("%lld %lld\n", ans.first, ans.second);
	return 0;
}