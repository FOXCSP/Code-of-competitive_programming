#include <bits/stdc++.h>

#define fi first
#define se second
#define all(X) X.begin(), X.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int N = 1e5 + 10;
int a[N], n, m, c[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> c[i];
	sort(a + 1, a + n + 1);
	sort(c + 1, c + m + 1);
	priority_queue<int, vector<int>, less<int>> heap;
	
	int cnt = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) cnt++;
		else {
			heap.push(cnt);
			cnt = 1;
		}
	}
	heap.push(cnt);

	ll ans = 0;
	for (int i = m; i >= 1; i--) {
		if (heap.empty()) break;
		auto t = heap.top();
		heap.pop();
		ans += min(c[i], t);
		if (t > c[i]) t -= c[i];
		else t = 0;
		if (t) heap.push(t);
	}
	cout << ans << '\n';
}

int main() {
	int _;
	cin >> _;
	while (_--)
	solve();
}