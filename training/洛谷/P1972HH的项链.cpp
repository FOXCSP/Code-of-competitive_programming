#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int ans[N], a[N];
int n, m;
template<class T>
struct BIT {
	T c[N];
	void modify(int x, T y) {
		for (x; x <= n; x += x & -x) c[x] += y;
	}
	T query(int x) {
		T s = 0;
		for (x; x; x -= x & -x) s += c[x];
		return s;
	}
};
BIT<int> c;
vector<array<int, 3>> evt;
int st[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		evt.push_back({r, l, i});
	}
	sort(evt.begin(), evt.end());
	int pre = 1;
	for (auto x : evt) {
		for (; pre <= x[0]; pre++) {
			if (st[a[pre]]) c.modify(st[a[pre]], -1);
			st[a[pre]] = pre;
			c.modify(pre, 1);
		}
		ans[x[2]] = c.query(x[0]) - c.query(x[1] - 1);
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}
// 结论： 对于每个端点, 有效的一定是靠近r的位置
// 做法就是枚举r, 每次将idx ~ r的值用树状数组维护
// ans : [l, r]的区间和