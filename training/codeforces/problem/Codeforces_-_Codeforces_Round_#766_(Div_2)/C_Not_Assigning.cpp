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

const int N = 100010;
int n;
int ru[N], cu[N];
int ans[N];
vi e[N];
map<pii, int> mp;
void dfs(int u, int fa, int o) {
	for (auto v : e[u]) {
		if (v == fa) continue;
		// printf("%d ", 5-o);
		ans[mp[{u, v}]] = 5-o;
		dfs(v, u, 5-o);
	}
}
void solve() {
	scanf("%d", &n);
	memset(ru, 0, sizeof ru);
	memset(cu, 0, sizeof cu);
	memset(ans, 0, sizeof ans);
	lep(i, 1, n) e[i].clear();
	lep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		cu[u]++, ru[u]++;
		cu[v]++, ru[v]++;
		e[u].pb(v);
		e[v].pb(u);
		mp[{u, v}] = i;
		mp[{v, u}] = i;
	}
	vi pos;
	lep(i, 1, n) {
		if (cu[i] == 1 && ru[i] == 1) pos.pb(i);
		if (cu[i] > 2 || ru[i] > 2) {
			printf("-1\n");
			return ;
		}
	}
	dfs(pos[0], 0, 3);
	lep(i, 1, n-1) printf("%d%c", ans[i], " \n"[i == n-1]);
}

int main() {
	int _;
	scanf("%d", &_);
	while (_--)
	solve();
	return 0;
}