#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define pb push_back
#define all(T) T.begin(), T.end()
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const int N = 101010;
int n, m, x, a[N];
vec<P(ll)> pe;


bool check(int t) {
	for (int i = 1; i + t <= n; i++) {
		ll cur = 1;
		for (int j = i; j <= i + t; j++) {
			ll p, q;
			p = pe[j].fi;
			q = pe[j].se;
			ll res = 1;
			while (q) {
				if (q & 1) {
					res = (res * p);
					if (res > x)
						return true;
				}
				q >>= 1;
				p = p * p;
				if (p > x) return true;
			}
			cur += res;
			if (cur > x) return true;
		}
	}
	return false;
}

void solve(int CaseT = 1) {
	cin >> n >> x;
	
	vec<P(int)> va;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) vx.pb({a[i], i});
	}
	
	ll ans = n + 1;
	for (int i = 0; i < SZ(va); i++) {
		ll res = 1;
		for (int j = i; j < SZ(va); j++) {
			res = res * va[j].fi; 
			if (res > x) {
				ans = min(ans, va[j].se - va[i].se + 1);
				break;
			}
		}
	}
	if (ans == n + 1)  cout << "-1\n";
	else cout << ans << '\n';

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
