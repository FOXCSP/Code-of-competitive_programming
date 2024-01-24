#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	long double a, b;
	cin >> a >> b;
	ll l = floor(sqrt(a)), r = floor(sqrt(b));
	ll ans = (r - l + 1) * 3ll;
	if(1ll * r * (r + 1) > b) ans -= 2;
	else if(1ll * r * (r + 2) > b) ans -= 1;

	if(1ll * l * (l + 1) < a) ans -= 2;
	else if(1ll * l * l < a) ans -= 1;
	cout << ans << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin >> _; while(_ --) solve();
	return 0;
}