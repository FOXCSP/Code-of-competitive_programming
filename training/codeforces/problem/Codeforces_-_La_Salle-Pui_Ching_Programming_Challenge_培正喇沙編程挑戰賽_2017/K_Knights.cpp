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

int n, m, k;
int g[110][110];
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		g[x][y] = 1;
	}
	int ans = (!g[1][1]) + (1 != m && !g[1][m]) + (n != 1 && !g[n][1]) + (n != 1 && m != 1 && !g[n][m]);
	cout << ans << '\n';
}

int main() {
	solve();
	return 0;
}