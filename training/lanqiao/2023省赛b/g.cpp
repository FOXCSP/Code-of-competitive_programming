#include <bits/stdc++.h>
#define int long long
#define vec vector
#define se second
#define fi first
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;

void solve (int Case) {
	int k;
	string s, a, b;
	cin >> k >> s >> a >> b;
	vec<int> posa, posb;
	int n = SZ(s);
	s = "#" + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] == a[0]) posa.pb(i);
		if (s[i] == b[0]) posb.pb(i);
	}
	
//	for (auto x : posa)cout << x << " ";
//	cout << '\n';
//	for (auto x : posb) cout << x << " ";
//	cout << '\n';
	
	ll ans = 0;
	for (int i = 0; i < SZ(posa); i++) {
		int l = posa[i];
		int r = l + k - 1;
		int p = lower_bound(posb.begin(), posb.end(), r) - posb.begin();
		if (SZ(posb) >= p) ans += (SZ(posb) - p);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
	for (int i=1; i<=_;i++) {
		solve(i);
	}
	return 0;
}
