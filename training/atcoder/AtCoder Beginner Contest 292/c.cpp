#include <bits/stdc++.h>
#define fi first
#define se second
#define lp (p<<1)
#define rp (p<<1|1)
#define pb emplace_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setop(T) cout<<fixed<<setprecision(T);
using namespace std;
using ll = long long;
ll calc(int x) {
	map<int, int> mp;
	for (int i = 2; i <= x / i; i++) {
		while (x % i == 0) {
			mp[i]++;
			x /= i;
		}
	}
	if (x > 1) mp[x]++;
	ll res = 1;
	for (auto [x, a]:mp) {
		res = 1ll * res * (a + 1);
	}
	return res;
}

void solve(int caseT) {
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		int x = i;
		int y = n - i;
		ll cx = calc(x);
		ll cy = calc(y);
		ans += cx * cy;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _;
	_=1;	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}