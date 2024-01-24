#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define left aaadd
#define right ccada

const int N = 500010;
int pos[N], l[N], r[N], n, k;
int right[N], left[N];
ll ans;
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int p; cin >> p;
		pos[p] = i;
	}
	for (int i = 0; i <= n + 1; i++) {
		l[i] = max(0, i - 1);
		r[i] = min(n + 1, i + 1);
	}
	for (int i = 1;i <= n; i++) {
		int x = pos[i];
		left[0] = x;
		for (int j = 1; j <= k; j++) {
			x = l[x];
			left[j] = x;
		}
		x = pos[i];
		right[0] = x;
		for (int j = 1; j <= k; j++) {
			x = r[x];
			right[j] = x;
		}
		x = pos[i];
		l[r[x]] = l[x];
		r[l[x]] = r[x];
		ll seg = 0;
		for (int j = 1; j <= k; j++) {
			// 不是很懂啊
			seg += 1ll * (left[j - 1] - left[j]) * (right[k - j + 1] - right[k - j]);
		}
		ans += seg * i;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}