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
vector<array<int, 3>> en;
int n, cu[N], ru[N], ans[N], idx;
void solve() {
	cin >> n;
	memset(ans, -1, sizeof ans);
	lep(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		cu[v]++, ru[v]++;
		cu[u]++, ru[u]++;
		en.pb({u, v, i});
	}
	for (auto v : en) {
		if ((cu[v[0]] == 1 && ru[v[0]] == 1) || 
			(cu[v[1]] == 1 && ru[v[1]] == 1)) {
			ans[v[2]] = idx++;
		}
	}
	for (auto v : en) {
		if (ans[v[2]] != -1) cout << ans[v[2]] << '\n';
		else cout << idx << '\n', idx++;
	}
}

int main() {
	solve();
	return 0;
}