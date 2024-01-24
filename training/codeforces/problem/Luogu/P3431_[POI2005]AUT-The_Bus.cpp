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

const int N = 100010;
int c[N], n, m, k;
vector<array<int, 3>> evt;
vector<int> vx;

void modify(int x, int y) {
	for (; x <= k; x += x & -x) c[x] = max(c[x], y);
}

int query(int x) {
	int s = 0;
	for (; x; x -= x & -x) s = max(s, c[x]);
	return s;
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		int x, y, p;
		scanf("%d%d%d", &x, &y, &p);
		evt.pb({x, y, p});
		vx.pb(y);
	}
	sort(all(vx));
	vx.erase(unique(all(vx)), vx.end());
	sort(all(evt));
	int ans = 0;
	for (auto e : evt) {
		int y = lower_bound(all(vx), e[1]) - vx.begin() + 1;
		int sum = query(y) + e[2];
		ans = max(ans, sum);
		modify(y, sum);
	}
	printf("%d\n", ans);
}

int main() {
	solve();
	return 0;
}