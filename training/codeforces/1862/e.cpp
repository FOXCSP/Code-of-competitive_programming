#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

void solve() {
	int n, m, d;
	cin >> n >> m >> d;
	priority_queue<int, vector<int>, greater<int>> heap;
	ll ans = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x <= 0) continue;
		heap.push(x);
		sum += x;
		while (SZ(heap) > m) sum -= heap.top(), heap.pop();
		ans = max(ans, sum - 1ll * i * d);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _ = 1;
	cin >> _;
	for (; _--; ) {
		solve();
	}
		
	return 0;
}
