#include <bits/stdc++.h>
#define fi first
#define se second
#define pb emplace
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

// --head--

void solve() {
	ll a, b, n, m;
	cin >> a >> b >> n >> m;
	ll ans1 = a * (n - n / (m + 1));
	ll ans2 = n * b;
	ll ans3 = (a * (n / (m + 1)) * m) + b * (n - n / (m + 1) * m - n / (m + 1));
	ans1 = min(ans1, ans2);
	ans1 = min(ans1, ans3);
	cout << ans1 << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _;
	cin >> _;
	while (_--) solve();
	return 0;
}
