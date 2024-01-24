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
const int N = 200010;
int ca[N], cb[N]; // ca[i]， 表示i送出去了， cb[i]表示收到了
int n, a[N];
void solve() {
	scanf("%d", &n);
	lep(i, 1, n) {
		scanf("%d", &a[i]);
		cb[a[i]]++;
		if (a[i]) ca[i]++;
	}
	vi p, q;
	lep(i, 1, n) {
		if (ca[i] && cb[i]) continue;
		if (!ca[i]) {
			p.pb(i);
		}
		if (!cb[i]) {
			q.pb(i);
		}
	}
	sort(all(p));
	sort(all(q));
	lep(i, 0, SZ(q) - 1) if (q[i] == p[i]) swap(q[i], q[(i+1)%SZ(q)]);
	lep(i, 0, SZ(q) - 1) a[p[i]] = q[i];
	lep(i, 1, n) printf("%d%c", a[i], " \n"[i == n]);
}

int main() {
	solve();
	return 0;
}