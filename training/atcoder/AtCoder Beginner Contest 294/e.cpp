#include <bits/stdc++.h>
#define fi first
#define se second
#define db double
#define lp (p<<1)
#define rp (p<<1|1)
#define vec vector
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define setdb cout<<fixed<<setprecision(12);
using namespace std;
typedef long long ll;
ll qmi(ll a, ll b, ll mod)
{ll res=1; while(b) { if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;} return res;}
/* -- head -- */

void solve(int Tcase = 1) {
	ll L, n, m;
	cin >> L >> n >> m;
	vec<P(ll)> v, w;
	for (int i = 1; i <= n; i++) {
		ll x, y;
		cin >> x >> y;
		v.pb({x, y});
	}
	for (int i = 1; i <= m; i++) {
		ll x, y;
		cin >> x >> y;
		w.pb({x, y});
	}
	int l = 0, r = 0;
	ll pl = 0, pr = 0, ans = 0, now;
	// l, r为 v, w 未处理的最后一个数
	while (l < n || r < m) {
		if (pl <= pr) {
			if (pl < pr) {
				auto [x, y] = v[l++];
				if (x == now) ans += min(pr - pl, y);
				pl += y;
				if (pl > pr) now = x;
			} else {
				auto [x, y] = v[l++];
				pl += y;
				now = x;
			}
		} else {
			auto [x, y] = w[r++];
			if (x == now) ans += min(pl - pr, y);
			pr += y;
			if (pr > pl) now = x;
		}
	}
	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _; 
	//	cin >> _;
	_=1;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
