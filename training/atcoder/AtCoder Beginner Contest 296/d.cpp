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
	ll n, m;
	cin >> n >> m;
	ll ans = 1e18;
	for (ll i = 1; i <= min(n, 2 * (ll)sqrt(m)); i++) {
		ll j = m / i + (m % i != 0);
		if (j > n) continue;
		if (i * j >= m) ans = min(ans, i * j);
	}
	cout << (ans==1e18?-1:ans) << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _; 
	_=1;
//	cin >> _;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
