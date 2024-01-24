#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
int n;
int pre[N], nxt[N], a[N];
bool query(int l, int r) {
	if (l > r) return true;
	for (int pl = l, pr = r; pl <= r; pl++, pr--) {
		if (pre[pl] < l && nxt[pl] > r) {
			return query(l, pl - 1) && query(pl + 1, r);
		}
		if (pre[pr] < l && nxt[pr] > r) {
			return query(l, pr - 1) && query(pr + 1, r);
		}
	}
	return false;
}

bool solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		if (mp.count(a[i])) pre[i] = mp[a[i]];
		else pre[i] = 0;
		mp[a[i]] = i;
	}
	mp.clear();
	for (int i = n; i >= 1; i--) {
		if (mp.count(a[i])) nxt[i] = mp[a[i]];
		else nxt[i] = n + 1;
		mp[a[i]] = i;
	}
	return query(1, n);
}

int main() {
	int _;
	scanf("%d", &_);
	while (_--) {
		puts(solve() ? "non-boring" : "boring");
	}
	return 0;
}