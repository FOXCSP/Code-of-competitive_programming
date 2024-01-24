#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
int g[N], f[N], n, m, a[N];
int pref[N], subf[N], sum;


void debug() {
	puts("pref:");
	for (int i = 1; i <= n; i++) printf("%d ", pref[i]);
	puts("\nsubf:");
	for (int i = 1; i <= n; i++) printf("%d ", subf[i]);
	puts("");
}

int main() {
	// freopen("1.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	memset(pref, 0xcf, sizeof pref);
	memset(subf, 0xcf, sizeof subf);
	pref[1] = a[1];
	for (int i = 2; i <= n; i++)
		pref[i] = max(pref[i - 1] + a[i], a[i]);
	for (int i = 2; i <= n; i++)
		pref[i] = max(pref[i - 1], pref[i]);

	subf[n] = a[n];
	for (int i = n - 1; i >= 1; i--)
		subf[i] = max(subf[i + 1] + a[i], a[i]);
	for (int i = n - 1; i >= 1; i--)
		subf[i] = max(subf[i + 1], subf[i]);

	// debug();
	int ans = - (1 << 30);
	// 没有跨过端点的
	for (int i = 1; i < n; i++)
		ans = max(ans, pref[i] + subf[i + 1]);

	// printf("ans: %d\n", ans);
	// 跨过端点的, 求出最小的两段子段和
	memset(pref, 0x3f, sizeof pref);
	memset(subf, 0x3f, sizeof subf);

	pref[1] = a[1];
	for (int i = 2; i <= n; i++)
		pref[i] = min(pref[i - 1] + a[i], a[i]);
	for (int i = 2; i <= n; i++)
		pref[i] = min(pref[i - 1], pref[i]);

	subf[n] = a[n];
	for (int i = n - 1; i >= 1; i--)
		subf[i] = min(subf[i + 1] + a[i], a[i]);
	for (int i = n - 1; i >= 1; i--)
		subf[i] = min(subf[i + 1], subf[i]);
	// debug();
	int res = 1 << 30;
	for (int i = 1; i < n; i++)
		res = min(res, pref[i] + subf[i + 1]);
	// printf("%d\n", sum - res);
	if (sum == res) printf("%d\n", ans);
	else printf("%d\n", max(ans, sum - res));
	return 0;
}