#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k, a, b;
void solve () {
	cin >> n >> k >> a >> b;
	if(a == b) {
		cout << "YES\n";
		return ;
	}
	ll c = max(a - 1, n - a);
	ll d = max(b - 1, n - b);
	if(k >= d || k >= c) {
		cout << "NO\n";
	}
	else cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	while(t --) solve();
	return 0;
}