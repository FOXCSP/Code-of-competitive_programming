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


const int N = 5010;
ll dp[N][N], n, m;
ll a[N], b[N];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[(i+1)/2];
	}
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			dp[i][j] = -1e18;
	dp[1][0] = 0; 
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + b[j]);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[n][i] + b[i]);
	}
	cout << ans << '\n';
}
int main() {
	solve();
	return 0;
}