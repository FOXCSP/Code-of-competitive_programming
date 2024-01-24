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

ll n, a[N], c, d;
ll s[N];

void solve() {
	cin >> n >> c >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, [&](int x, int y) {
		return x > y;
	});
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	if (d * s[1] < c) {
		cout << "Impossible\n";
	} else if (s[min(d, n)] >= c) {
		cout << "Infinity\n";
	} else {
		ll ans = 0;
		for (ll i = d; i >= 0; i--) {
			ll x = (d % (i + 1));
			if (s[min(i + 1, n)] * (d / (i + 1)) + s[min(x, n)] >= c) {
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}

}


int main() {
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}