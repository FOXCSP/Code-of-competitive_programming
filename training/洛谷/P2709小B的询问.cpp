#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 50010;

vector<array<int, 3>> ev;
ll a[N], b[N], c, ans[N];
int n, m, k;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		ev.push_back({l, r, i});
	}
	sort(ev.begin(), ev.end());
	auto add = [&] (int x) {
		c += 2 * b[x] + 1;
		b[x]++;
	};
	auto del = [&] (int x) {
		c -= 2 * b[x] - 1;
		b[x]--;
	};
	int l = 1, r = 0;
	for (auto e : ev) {
		int L = e[0], R = e[1], i = e[2];
		while (r < R) r++, add(a[r]);
		while (l < L) del(a[l]), l++;
		while (r > R) del(a[r]), r--;
		// printf("%d %d\n", L, R);
		ans[i] = c;
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}