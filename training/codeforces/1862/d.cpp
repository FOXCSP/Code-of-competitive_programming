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
	ll n;
	cin >> n;
	ll ans = max(2ll, (ll)sqrt(2 * n));
	while (ans * (ans - 1) / 2 >= n) ans--;	
	while (ans * (ans - 1) / 2 < n) ans++;
	if (ans * (ans - 1) / 2 == n) {
		cout << ans << '\n';
	} else {
		ans--;
		cout << ans + n - (ans * (ans - 1) / 2) << '\n';
	}
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
