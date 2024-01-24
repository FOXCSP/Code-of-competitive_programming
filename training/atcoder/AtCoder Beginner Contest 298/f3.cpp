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
ll qmi(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return res;
}


multiset<P(ll)> s;
void solve(int CaseT = 1) {
	cin >> n;
	map<int, ll> l, r;
	vec<array<int, 3>> vx;
	map<int, vec<P(ll)>> pos;
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		l[u]+=w;
		r[v]+=w;
		vx.pb({u, v, w});
		pos[v].pb({w, u});
	}
	
	for (auto x : vx)
		for (auto &y : pos[x[1]])
			y.fi = l[y.se];

	for (auto x : l)
		s.insert({x.se, x.fi});
		
	ll ans = 0;
	for (auto x : vx)
		ans = max(ans, l[x[0]] + r[x[1]] - x[2]);

	for (auto x : vx) {
		for (auto y : pos[x[1]]) {
			s.erase(s.find(y));
		}
		if (!s.empty())
			ans = max(ans, (*prev(s.end())).fi + r[x[1]]);
		for (auto y : pos[x[1]]) {
 			s.insert(s.find(y));
 		}
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
