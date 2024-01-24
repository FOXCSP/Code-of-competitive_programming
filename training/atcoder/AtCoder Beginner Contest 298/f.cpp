#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define all(T) T.begin(), T.end()
#define pb push_back 
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));
const ll mod = 998244353; 
int n, m;
void solve(int CaseT = 1) {
	cin >> n;
	map<int, ll> l, r;
	multiset<P(ll)> S; 
	map<int, vec<P(int)>> pos;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		l[x]+=z;
		r[y]+=z;
		pos[y].pb({x, z});
	}
	
	for (auto [x, y] : l) {
		S.insert(MP(y, y));
	}
	
	ll ans = 0;
	
	for (auto [y, ve] : pos) {
		for (auto [x, z] : ve) {
			S.erase(S.find(MP(l[x], l[x])));
			S.insert(MP(l[x] - z, l[x] - z)); 
		}
		if (!S.empty())
			ans = max(ans, (*S.rbegin()).fi + r[y]);

		for (auto [x, z] : ve) {
			S.erase(S.find(MP(l[x] - z, l[x] - z))); 
			S.insert(MP(l[x], l[x]));
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int _;
	_ = 1;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
} 
