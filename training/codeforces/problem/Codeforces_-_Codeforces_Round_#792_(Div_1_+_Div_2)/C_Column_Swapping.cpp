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

int n, m;
void solve() {
	cin >> n >> m;
	VI now;
	bool f = true;
	int id;
	vector<vector<int>> g(n + 1), gg(n + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			g[i].pb(x);
		}
		VI res = g[i];
		sort(res.begin(), res.end());
		for (int j = 0; j < m; j++) {
			if (res[j] != g[i][j]) gg[i].pb(j);
		}
		if (SZ(now)) {
			if (!SZ(gg[i])) {
				if (g[i][now[0]] != g[i][now[1]]) f = false;
			} else if (gg[i] != now) {
				f = false;
			}
		}
		if (!SZ(now) && SZ(gg[i])) now = gg[i], id = i;
	}
	if (!f || SZ(now) > 2) {
		cout << "-1\n";
		return;
	}
	if (SZ(now)) {
		for (int i = id - 1; i >= 0; i--) {
			if (SZ(gg[i]) && gg[i] != now) {
				cout << "-1\n";
				return ;
			}
			if (!SZ(gg[i]) && g[i][now[0]] != g[i][now[1]]) {
				cout << "-1\n";
				return ;
			}
		}
		cout << now[0] + 1 << " " << now[1] + 1 << '\n';
	} else {
		cout << "1 1\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _; cin >> _;
	while (_--)
	solve();
	return 0;
}