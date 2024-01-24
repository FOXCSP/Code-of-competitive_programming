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
void solve() {
	cin >> n >> m >> k;
	int f = int(n < m);
	if (n < m) {
		swap(n, m);
	}
	int t1 = k / 2, t2 = k % 2;
	int t3, cnt = 0;
	if (t1) t3 = (m - t2) / t1;
	else t3 = 0;
	string c1 = "1", c2 = "0", ans = "";
	for (int i = 1; i <= t1; i++) {
		ans = ans + char('0' + f);
		if (i < t1) {
			ans = ans + char('0' + 1 - f); cnt++;
		} else {
			for (int j = 1; j <= m - i + 1 - t2; j++)
				ans = ans + char('0' + 1 - f), cnt++;
		}
	}
	ans = ans + char('0' + f);
	if (t2) for (int i = cnt + 1; i <= m; i++) ans = ans + char('0' + 1 - f);
	for (int i = t1 + 2; i <= n; i++) ans = char('0' + f) + ans;
	cout << ans << '\n';
}

int main() {
	solve();
	return 0;
}