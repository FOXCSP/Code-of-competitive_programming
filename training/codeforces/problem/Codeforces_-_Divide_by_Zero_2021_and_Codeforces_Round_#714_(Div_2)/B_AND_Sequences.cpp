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
#define SZ(x) (x.size())
#define vl vector<ll>;
#define vpp vector<pii>
#define lep(i, x, y) for (int i=(x);i<=(y);i++)
#define rep(i, y, x) for (int i=(y);i>=(x);i--)
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ull=unsigned long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
inline ll read() {
	ll s=0,f=1; char c = getchar();
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while ('0' <= c && c<='9') {s=s*10+c-'0';c=getchar();}
	return s*f;
}
void print(ll x) {if (!x) return ; if (x>9) print(x/10); putchar(x%10+'0');}
const int Mod = 1e9+7;
// --head--
const int N=200010;
int a[N];
ll je[N];
void solve() {
	int n = read();
	int mn = 1 << 30;
	map<int, ll> mp;
	lep(i, 1, n) {
		a[i] = read();
		mp[a[i]]++;
		mn = min(mn, a[i]);
	}
	if (mp[mn] < 2) {
		printf("0\n");
		return ;
	}
	lep(i, 1, n) {
		if ((mn & a[i]) != mn) {
			printf("0\n");
			return ;
		}
 	}
 	ull ans = ((1ull * mp[mn] * 1ull*(mp[mn]-1)) % Mod * je[n-2]%Mod) % Mod;
 	printf("%llu\n", ans);
}

signed main() {
	je[0] = 1;
	lep(i, 1, N-1) {
		je[i] = (1ll*je[i-1]*i)%Mod;
	}
	int _ = read();
	while (_--) solve();
	return 0;
}