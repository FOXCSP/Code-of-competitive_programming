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

const int N = 110;
int n, m;
int g[N][N], d[N][N];
char c[N][N];
vector<array<int, 4>> ans;
void solve() {
	cin >> n >> m;
	ans.clear();
	ans.pb({1, 1, n, m});
	for (int i = 1; i <= n; i++) d[i][0] = 1 - d[i - 1][0];
	for (int i = 1; i <= n; i++) cin >> c[i] + 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) d[i][j] = 1 - d[i][j - 1];
	// for (int i = 1; i <= n; i++) {for (int j = 1; j <= m; j++) cout << d[i][j] << " "; cout <<'\n';}
	for (int j = 1; j <= m; j++) for (int i = n; i > 1; i--) {
		if (d[i][j] == 1 && c[i][j] == '0') ans.pb({i, j, i, j});
		else {
			if (d[i][j] == 0 && c[i][j] == '1') {
				ans.pb({i-1,j,i,j});
				d[i-1][j] = 0;
				d[i][j] = 1;
			}
		}
	}
	for (int j = m; j > 1; j--) {
		if (d[1][j] == 1 && c[1][j] == '0') ans.pb({1, j, 1, j});
		else {
			if (d[1][j] == 0 && c[1][j] == '1') {
				ans.pb({1,j - 1, 1, j});
				d[1][j - 1] = 0;
				d[1][j] = 1;
			}
		}
	}
	if (d[1][1] != c[1][1] - '0') cout << "-1\n";
	else {
		cout << SZ(ans) << '\n';
		for (auto [a, b, c, d] : ans) {
			cout << a << " " << b << " " << c << " " << d << '\n';
		}
	}
}

int main() {
	int _; cin >> _; while (_-- ) solve();
	return 0;
}