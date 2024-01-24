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
#define VPP vector<PII>
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
const int N = 310;
int g[N][N], n, m, x, y, id, k;
void solve() {
	cin >> n >> m >> k;
	VPP ans[k + 1];
	x = min(n, m), y = max(n, m);
	for (int i = 1; i <= y; i += 2) {
		for (int j = 1; j <= x; j++) {
			if (id < k - 1) {
				if (i + 1 <= y) {
					g[i][j] = g[i + 1][j] = 1;
					ans[id].pb({i, j}); ans[id].pb({i + 1, j});
				} else {
					g[i][j] = g[i][j + 1] = 1;
					ans[id].pb({i, j}); ans[id].pb({i, j + 1});
				}
				id++;
			}
		}
	}
	for (int i = 1; i <= y; i++) {
		VPP res;
		for (int j = 1; j <= x; j++) {
			if (!g[i][j]) res.pb({i, j});
		}
		if (i&1) reverse(res.begin(), res.end());
		for (auto v : res) ans[id].pb(v);
	}
	for (int i = 0; i <= id; i++) {
		cout << SZ(ans[i]) << " ";
		for (auto [a, b] : ans[i]) {
			if (n < m) swap(a, b);
			cout << a << " " << b << " ";
		}
		cout << '\n';
	}
}

int main() {
	solve();
	return 0;
}