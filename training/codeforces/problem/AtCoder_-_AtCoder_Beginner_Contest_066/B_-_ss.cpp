#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define PII pair<int,int>
#define PLL pair<ll, ll>
#define VI vector<int>
#define SZ(x) ((int)x.size())
#define VL vector<ll>;
#define VPP vector<PII>
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--


typedef pair<int, int> hasv;
const ll mod1 = 1000000007;
const ll mod2 = 1000000009;
const ll base1 = 13331;
const ll base2 = 23333;

const int N = 1010;

hasv p[N], t[N];

hasv operator + (hasv a, hasv b) {
	int c1 = a.fi + b.fi;
	int c2 = a.se + b.se;
	if (c1 > mod1) c1 -= mod1;
	if (c2 > mod2) c2 -= mod2;
	return hasv{c1, c2};
}

hasv operator * (hasv a, hasv b) {
	return hasv{1ll * a.fi * b.fi % mod1, 1ll * a.se * b.se % mod2};
}

hasv operator - (hasv a, hasv b) {
	int c1 = a.fi - b.fi;
	int c2 = a.se - b.se;
	if (c1 < 0) c1 += mod1;
	if (c2 < 0) c2 += mod2;
	return hasv{c1, c2};
}

void solve() {
	string s; cin >> s;
	int n = SZ(s);
	s = "@" + s;
	p[0] = {1, 1};
	hasv base = {base1, base2};
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * base;
		t[i] = t[i - 1] * base + hasv{s[i], s[i]};
	}
	int ans = 0;
	for (int i = n - 1; i >= 1; i--) {
		if (i & 1) continue;
		int l = 1, r = i;
		int mid = r / 2;
		hasv h1 = t[r] - t[mid + 1 - 1] * p[r - (mid + 1) + 1];
		hasv h2 = t[mid] - t[l - 1] * p[mid - l + 1];
		// cout << h1.fi << " " << h2.fi << '\n';
		// cout << h1.se << " " << h2.se << '\n';

		if (h1 == h2) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
}

int main() {
	solve();
	return 0;
}