#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
typedef double db;
// head

const int N = 1000010, mod = 998244353;

int a[N], n, m, cnt[N];
map<int, int> mp; 
void solve(int CaseT) {
	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int u,v;
//		cin >> u >> v;
//		a[u]++;
//		a[v]++;
//	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		mp[a[i]]++; 
	}
	
	vector<pair<int, int>> vx;
	for (auto x : mp) {
		vx.pb(x);
	}
	
	ll ans = 0;
	for (int i = 0; i < SZ(vx); i++) {
		for (int j = i; j < SZ(vx); j++) {
			int du = vx[i].fi;
			int dv = vx[j].fi;
			int tmp = (du ^ dv) * (du & dv) % mod * (du | dv) % mod;
			ans = (ans + (tmp * vx[i].se % mod * vx[j].se % mod) % mod) % mod;
		}
	}
	cout << ans << '\n';

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
//	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}
/*
6 1
5 5 8 9 9 8 
*/
