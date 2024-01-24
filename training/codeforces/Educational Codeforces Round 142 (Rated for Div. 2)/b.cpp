#include <bits/stdc++.h>
#define fi first
#define se second
#define all(X) X.begin(), X.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll x = abs(b - c);
	ll y = min(x, a);
	ll t = max(0ll, a - y);
	ll ans = a + (a > 0) * (min(b, c) * 2) + y + min(d, t);
	// ll ans = a + (a > 0) * (min(b, c) * 2) + min(x, a) + min(d, max(0ll, a - min(x, a)));
	if (ans < (a + b + c + d)) ans++;
	cout << min(ans, a + b + c + d) << '\n';
}

int main() {
	int _; cin >> _;
	while (_--)
	solve();
	return 0;
}