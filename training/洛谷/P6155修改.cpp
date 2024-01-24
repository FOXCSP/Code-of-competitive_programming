#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
const int N = 1000010;
int n, a[N], b[N];
map<int,int> mp;
vector<int> v;
stack<int> stk;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mp[a[i]]++;
	}
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	sort(b + 1, b + n + 1);
	sort(a + 1, a + n + 1);
	int now = 1, nowpos = 1;
	while (1) {
		if (!stk.size()) {
			if (now <= n) {
				nowpos = a[now];
			} else break;
		}
		while (now <= n && a[now] == nowpos) stk.push(a[now]), now++;
		auto t = stk.top(); stk.pop();
		v.push_back(nowpos - t);
		nowpos++;
	}
	ull ans = 0;
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 1; i <= n; i++) ans += 1ull * v[i - 1] * b[i];
	printf("%llu\n", ans);
	return 0;
}