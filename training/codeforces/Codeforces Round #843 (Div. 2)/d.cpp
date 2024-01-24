#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define fi first
#define se second

const int N = 200010, M = 100010;
ll n, x, m;
void solve() {
	cin >> n >> x;
	ll f = 0, res = 0;
	for (ll i = 0; i <= 62; i++) {
		ll a = x >> i & 1ll, b = n >> i & 1ll;
		f |= a;
		if (f && (a != b)) {
			cout << "-1\n";
			return ;
		}
		if (!f) res += (1ll << i) * b;
	}
	for (ll i = 62; i >= 0; i--) {
		if (res >> i & 1) {
			if (x >> (i + 1) & 1) {
				cout << "-1\n";
				return ;
			}
			n &= x;
			n |= (1ll << (i + 1));
			break;
		}
	}
	cout << n << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	int _; cin >> _;
	while(_--) {
		solve();
	}
	return 0;
}