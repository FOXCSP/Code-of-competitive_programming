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

const int N = 50010;
int n, m, k;
int a[N], b[N];
PLL x[N], y[N];
int xd, yd;
void solve() {
	cin >> n >> m;
	xd = yd = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int t = a[i];
		int cnt = 0;
		while (t % m == 0) cnt++, t /= m;
		if (xd && x[xd].fi == a[i] / qmi(m, cnt, Mod)) {
			x[xd].se += qmi(m, cnt, Mod);
		} else {
			x[++xd] = PII{a[i] / qmi(m, cnt, Mod), qmi(m, cnt, Mod)};
		}
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> b[i];
		int t = b[i];
		int cnt = 0;
		while (t % m == 0) cnt++, t /= m;
		if (yd && y[yd].fi == b[i] / qmi(m, cnt, Mod)) {
			y[yd].se += qmi(m, cnt, Mod);
		} else {
			y[++yd] = PII{b[i] / qmi(m, cnt, Mod), qmi(m, cnt, Mod)};
		}
	}
	bool f = (xd == yd);
	for (int i = 1; i <= min(xd, yd); i++) {
		if (x[i] != y[i]) {
			// cout << x[i].fi << " " << x[i].se << "\n";
			// cout << y[i].fi << " " << y[i].se << "\n";
			f = false;
			break;
		}
	}
	if (f) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	int _;
	cin >> _; while (_--)
	solve();
	return 0;
}