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
const int N = 300010;
const ll mod = 1000000007;
int n, m;
ll c[N], l, r;
ll s[N], a[N];

void modify(int x, int y) {
	for (; x <= m; x += x & -x) 
		c[x] += y;
}

ll query(int x) {
	ll s = 0;
	for (; x; x -= x & -x)
		s += c[x];
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	
	
	vec<ll> vx;
	for (int i = 1; i <= n; i++) {
		vx.pb(s[i] - l);
		vx.pb(s[i] - r);
		vx.pb(s[i]); 
	}
	vx.pb(0);
	vx.pb(-1e9);
	sort(all(vx));
	vx.erase(unique(all(vx)), vx.end());
	m = SZ(vx);
	
	ll ans = 0;
	modify(lower_bound(all(vx), 0) - vx.begin() + 1, 1);
	for (int i = 1; i <= n; i++) {
		int p = lower_bound(all(vx), s[i] - l) - vx.begin() + 1;
		int q = lower_bound(all(vx), s[i] - r) - vx.begin() + 1;
		ans += query(p) - query(q - 1);  
		p = lower_bound(all(vx), s[i]) - vx.begin() + 1;
		modify(p, 1);
	}
	cout << ans << '\n'; 
	 
	return 0;
}
