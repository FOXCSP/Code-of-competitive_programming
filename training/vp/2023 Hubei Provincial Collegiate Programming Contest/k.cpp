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
ll qmi(ll a, ll b) {
	a %= mod;
	ll res=1;
	for (; b; b >>= 1) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
	}
	return res;
}
void solve(int CaseT) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cout << qmi(m - i, n) * qmi(qmi(m - 1, n), mod - 2) % mod << '\n';
	}
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
