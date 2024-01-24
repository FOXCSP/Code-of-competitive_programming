#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T> 
#define vec vector
#define fi first
#define se second
#define pb push_back
#define all(T) T.begin(), T.end()
using namespace std;
typedef long long ll;
const int N = 100010;
const ll mod = 1000000007;

/*
6
9 R
10 L
3 R
1 R
3 R
4 L

10
*/

int n, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	vec<P(ll)> vx, pos;
	ll p = 0;
	for (int i = 1; i <= n; i++) {
		ll x;
		char f;
		cin >> x >> f;
		if (f == 'L') vx.pb({p - x, 1}), vx.pb({p, -1}), pos.pb({p - x, p}) ,p = p - x;
		else vx.pb({p, 1}), vx.pb({p + x, - 1}), pos.pb({p, p + x}), p = p + x;
	}
	
	sort(all(vx));
	
	int now = vx[0].se;	
	ll ans = 0;
	for (int i = 1; i < SZ(vx); i++) {
		if (now >= k) ans += vx[i].fi - vx[i - 1].fi;
		now += vx[i].se;
	}
	cout << ans << '\n';
	return 0;
}
