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
const int Mod = 1e9+7;
// --head--

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
char c[110][110];
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> c[i] + 1;
	vector<vector<int>> ans(n + 1, vector<int> (m + 1, -1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int cnt = 0;
			if (c[i][j] == '#') continue;
			for (int k = 0; k < 8; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x < 1 || x > n || y < 1 || y > m) continue;
				if (c[x][y] == '#') cnt++;
			}
			ans[i][j] = cnt;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (ans[i][j] != -1) cout << ans[i][j];
			else cout << "#";
		cout << '\n';
	}
}

int main() {
	solve();
	return 0;
}