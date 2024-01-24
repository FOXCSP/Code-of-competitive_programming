#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;
double pi = acos(-1);

const int mod = 1e9 + 7;
void solve() {
	int n;
	cin >> n;
	int k = 0;
	while ((1ll << (k + 1)) - 1 <= n) {
		k++;
	}
	int ans = n;
	for (int i = 0, res = k - 1; i < k; i++) {
		ans = (ans + res * (1ll << i)) % mod;
		res--;
	}
	int m = n - (1ll << k) + 1;
	while (m) {
		ans = (ans + m/2) % mod;
		m/=2;
	}
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int _;
	cin >> _;
	for (int i = 1; i <= _; i++) {
		solve();
	}
	return 0; 
} 
