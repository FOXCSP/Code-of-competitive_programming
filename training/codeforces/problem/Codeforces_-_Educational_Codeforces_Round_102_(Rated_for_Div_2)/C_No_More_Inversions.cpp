#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vi vector<int>
#define SZ(x) ((int)x.size())
#define vl vector<ll>;
#define vpp vector<pii>
#define lep(i, x, y) for (int i=(x);i<=(y);i++)
#define rep(i, y, x) for (int i=(y);i>=(x);i--)
#define all(x) x.begin(), x.end()
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

int n, k, ans[200010];
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= 2 * k - n - 1; i++) ans[i]=i;
	for (int i = 2 * k - n, j = k; j >= 2 * k - n; j--,i++) ans[i] = j;
	for (int i = k + 1,j = k - 1;i <= n;i++,j--) ans[i] = ans[j];
	for (int i = 1; i <= k; i++) cout << ans[i] << ' ';
	cout <<'\n';
}

int main() {
	int _; cin >> _ ; while (_ --) solve();
	return 0;
}