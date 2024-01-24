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

const int N = 100010;
ll a[N], n, m;
ll ans;
ll st[N];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], m = max(m, a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int l = 0, r = min(n, a[i]) + 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (a[mid] >= i) r = mid;
			else l = mid + 1;
		}
		ans += (min(n, a[i]) - l + 1) - (a[i] >= i);
	}
	cout << ans << '\n';
}

int main() {
	solve();
	return 0;
}