#include <bits/stdc++.h>
#define fi first
#define se second
#define db double
#define lp (p<<1)
#define rp (p<<1|1)
#define vec vector
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define setdb cout<<fixed<<setprecision(12);
using namespace std;
typedef long long ll;
ll qmi(ll a, ll b, ll mod)
{ll res=1; while(b) { if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;} return res;}
/* -- head -- */

const int N = 31, M = 51, inf = 1e9;
int f[N][N][M];

int dp(int n, int m, int k) {
	int &x = f[n][m][k];
	if (k == 0) return x = 0;
	if (x != -1) return x;
	if (k == n * m) return x = 0;
	x = inf;
	for (int i = 1; i < n; i++){
		if (k) x = min(x, dp(n - i, m, k) + m * m);
		if (k >= i * m) x = min(x, dp(n - i, m, k - i * m) + m * m);
	}
		
	for (int i = 1; i < m; i++) {
		if (k) x = min(x, dp(n, m - i, k) + n * n);
		if (k >= i * n) x = min(x, dp(n, m - i, k - i * n) + n * n); 
	}
	return x;
}

void solve(int Tcase = 1) {
	int n, m, k;
	cin >> n >> m >> k;
	dp(n, m, k);
//	cout << dp(n, m, k) << '\n';
	cout << f[n][m][k] << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _; 
	cin >> _;
	memset(f, -1, sizeof f);
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
