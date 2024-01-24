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

void solve() {
	string s;
	cin >> s;
	int n = SZ(s);
	ll ans = 0, m = 0;
	for (int i = 0; i < n; ) {
		if (s[i] == '<') {
			ll cnt = 0;
			while (i < n && s[i] == '<') i++, cnt++;
			// <<<<
			ans += (cnt - 1) * cnt / 2;
			m = cnt;
		} else {
			ll cnt = 0;
			while (i < n && s[i] == '>') i++, cnt++;
			// >>>>
			if (cnt < m) ans += m + (cnt - 1) * cnt / 2;
			else ans += (cnt + 1) * cnt / 2;
			m = 0;
		}
	}
	if (m) ans += m;
	cout << ans << '\n';
}

int main() {
	solve();
	return 0;
}