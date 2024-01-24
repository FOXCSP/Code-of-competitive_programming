#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define PII pair<int,int>
#define VI vector<int>
#define SZ(x) ((int)x.size())
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--

const int N = 200010;

int n, a[N];

void solve() {
	cin >> n;
	vector<ll> s(n + 1, 0), f(n + 1, 0);
	ll cnt = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = cnt;
		if (a[i] == 1) cnt++;
		else ans += cnt;
	}
	cnt = 0;
	for (int i = n; i >= 1; i--) {
		f[i] = cnt;
		if (a[i] == 0) cnt++;
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			res = max(res, s[i] - f[i]);
		} else {
			res = max(res, f[i] - s[i]);
		}
	}
	cout << ans + max(0ll, res) << '\n';
}


int main() {
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}