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
#define VPP vector<pii>
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
inline ll read() {
	ll s=0,f=1; char c = getchar();
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while ('0'<= c&&c<='9') {s=s*10+c-'0';c=getchar();}
	return s*f;
}
void print(ll x) {if (!x) return ; if (x>9) print(x/10); putchar(x%10+'0');}
const int Mod = 1e9+7;
// --head--

int n;
string s, t;
void solve() {
	cin >> n >> s >> t;
	int a = 0, b = 0;
	VI va, vb;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			if (s[i] == 'a') a++, va.pb(i + 1);
			else b++, vb.pb(i + 1);
		}
	}
	a %= 2;
	b %= 2;
	if ((!a && !b ) || (a && b)) {
		cout << (SZ(va) + 1) / 2 + (SZ(vb) + 1) / 2 << '\n';
		for (int i = (SZ(va)&1); i < SZ(va); i += 2) {
			cout << va[i] << " " << va[i + 1] << '\n'; 
		}
		for (int i = (SZ(va)&1); i < SZ(vb); i += 2) {
			cout << vb[i] << " " << vb[i + 1] << '\n'; 
		}
		if (a && b) {
			cout << va[0] << " " << va[0] << '\n';
			cout << va[0] << " " << vb[0] << '\n';
		}
	} else {
		cout << "-1\n";

	}
}

int main() {
	solve();
	return 0;
}