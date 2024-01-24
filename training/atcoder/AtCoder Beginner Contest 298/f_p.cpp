#include <bits/stdc++.h>
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

const int N = 110;
const ll mod = 998244353; 
int n, m;
set<P(ll)> s;
void solve(int CaseT = 1) {
	cin >> n;
	map<int, ll> l, r;
	vec<P(ll)> vx;
	map<int, vec<int>> pos;
	map<P(int), int> point;
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		l[u]+=w;
		r[v]+=w;
		vx.pb({u, v});
		pos[v].pb(u);
		point[{u, v}] = w;
	}
	
	for (auto x : l)
		s.insert({x.se, x.fi});
		
	ll ans = 0;

	for (auto x : vx)
		ans = max(ans, l[x.fi] + r[x.se] - point[{x}]);

	for (auto x : r) {
		for (auto y : pos[x.se])
			s.erase({l[y], y});
		if (!s.empty())
			ans = max(ans, (*s.rbegin()).fi + r[x.se]);
		for (auto y : pos[x.se])
			s.insert({l[y], y});
	}
	
	cout << ans << '\n';	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
//	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
} 
