#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
// head

const int N = 1000010;
int n;
int g[25][N], f[25][N];
int a[N], lg[N];
void init() {
//	memset(f, 0, sizeof f);
//	memset(g, 0x3f, sizeof g);
//	
	for (int i = 1; i <= n; i++)
		g[0][i] = f[0][i] = a[i];
		
	lg[1] = 0, lg[2] = 1;
	for (int i = 3; i <= n; i++)
		lg[i] = lg[i / 2] + 1;
	
	
	for (int i = 1; i < 25; i++)
		for (int j = 1; j + (1 << i) - 1 <= n; j++)
			f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]),
			g[i][j] = min(g[i - 1][j], g[i - 1][j + (1 << (i - 1))]); 
}

int getmin(int l, int r) {
	int k = lg[r - l + 1];
	return min(g[k][l], g[k][r - (1 << k) + 1]); 
}

int getmax(int l, int r) {
	int k = lg[r - l + 1];
	return max(f[k][l], f[k][r - (1 << k) + 1]);
}

void solve(int CaseT) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	init();
//	cout << getmin(1, n) << " " << getmax(1, n) << '\n'; 
	ll ans = 0;
	for (int k = 1; k <= n; k++) {
		bool ok = true;
		int x = -(1 << 30);
		for (int l = 1, r = k; l <= n && ok; l += k, r += k) {
			r = min(r, n);
			int mn = getmin(l, r);
			int mx = getmax(l, r);
			if (mn < x) {
				ok = false;
			}
			x = mx;
		}
		if (ok) {
			ans++;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
//	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}

