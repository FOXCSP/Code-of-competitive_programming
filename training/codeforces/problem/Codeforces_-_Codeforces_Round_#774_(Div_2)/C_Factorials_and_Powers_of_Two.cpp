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
#define VL vector<ll>
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

VL v;
ll n, m = 1e12;
int st[15], ans = 1 << 30;
int calc(ll w) {
	int cnt = 0;
	while (w) {w = w & (w - 1); cnt++;}
	return cnt;
}
void dfs(int x, ll w, int cnt) {
	ans = min(ans, cnt + calc(w));
	if (x == SZ(v) || v[x] > w) {
		return ;
	}
	dfs(x + 1, w - v[x], cnt + 1);
	dfs(x + 1, w, cnt);
}
void solve() {
	cin >> n;
	ans = 1 << 30;
	dfs(0, n, 0);
	cout << ans << '\n';
}

int main() {
	for (ll i = 2, k = 1; k <= m; i++) {
		v.pb(k);
		k *= i;
	}
	int _; cin >> _;
	while (_--) solve();
	return 0;
}