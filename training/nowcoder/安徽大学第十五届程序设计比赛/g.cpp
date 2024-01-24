#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define fi first
#define se second
#define P(T) pair<T, T>
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define all(T) T.begin(), T.end()
#define pb push_back 
using namespace std;
typedef long long ll;
typedef long double ldb;
//  head

const ll mod = 998244353;
ll qmi(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

void solve(int CaseT = 1) {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll x = (b * (1 - b * d * (b - a) * (d - c)) % mod + mod) % mod;
	ll inv = qmi(x, mod - 2);
	cout << (a * inv) % mod << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_=1;
	cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	
	return 0;
}
