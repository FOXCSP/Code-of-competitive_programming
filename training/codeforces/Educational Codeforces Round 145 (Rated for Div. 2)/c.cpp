#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
using ll = long long;

const int inf = 1e9, mod = 998244353;

map<int, int> mp;
vec<int> vx;
void solve(int caseT = 1) {
	int n, k;
	cin >> n >> k;
	
	vec<int> res;

	for (auto x : vx) {
		while (k >= x) k -= x, res.pb(mp[x]);
	}
	vec<int> ans;
	
	for (int i = 0; i < SZ(res); i++) {
		int x = res[i];
		while (x > 0) {
			ans.pb(1);
			x--;
		}
		if (i != SZ(res) - 1) ans.pb(-1000);
	}
	
	while (SZ(ans) < n) {
		ans.pb(-1000);
	}
	
	if (SZ(ans) > n) {
		ans.pop_back();
		ans.pop_back();
		ans.back()++;
		ans.pb(-1);
	}
	
//	cout << SZ(ans) << '\n';
	
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int x = 30; x >= 1; x--) {
		vx.pb(x * (x + 1) / 2);
		mp[x * (x + 1) / 2] = x;
	}

	int _;
	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	
	return 0;
}

