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
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cout << i << " " << j << " " <<  ((a[j] ^ a[i])*(a[j]&a[i])*(a[j]|a[i])) << '\n';
			ans = (ans + ((a[j] ^ a[i])*(a[j]&a[i])*(a[j]|a[i]))) % mod;
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
