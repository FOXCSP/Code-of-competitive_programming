#include <bits/stdc++.h>

#define fi first
#define se second
#define all(X) X.begin(), X.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int N = 2e5 + 10;
ll a[N], n;

void solve() {
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	ll ans = 0;
	for (int i = 1; i <= n - 1; i++) {
		ans = max(ans, __gcd(a[i], a[n] - a[i]));
	}
	cout << ans <<'\n';
}
int main() {
	int _;
	cin >> _;
	while (_--)
	solve();
}

