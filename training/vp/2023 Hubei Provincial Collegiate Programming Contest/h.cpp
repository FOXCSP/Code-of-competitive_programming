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
void solve(int CaseT) {
	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int u,v;
//		cin >> u >> v;
//		a[u]++;
//		a[v]++;
//	}

	
	for (int i = 1; i <= n; i++)
		cin >> a[i], cnt[a[i]]++;
	int tmp = 1 << 17 - 1;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " hs: ";
		for (int j = a[i]; j; j = (j - 1) & a[i]) {
			ll t = (j ^ a[i]) * (j | a[i]) % mod * (j & a[i]) % mod;
			t = (t + mod) % mod;
			ll res = t;
			if (cnt[j]) {
				cout << j << " " << res << " xx\n";
				ans = (ans + res) % mod;
			}
				
		}
		cout << '\n';
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
