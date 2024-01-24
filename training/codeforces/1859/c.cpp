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

const int N = 25010;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) a[i] = i;
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		vector<int> b(a);
		reverse(b.begin() + i + 1, b.end());
		ll mx = 0, sum = 0;
		for (int j = 1; j <= n; j++)
			sum += j * b[j], mx = max(mx, 1ll * j * b[j]);
		ans = max(ans, sum - mx);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _ = 1;
	cin >> _;


	while (_--) {
		solve();
	}
	return 0;
} 
