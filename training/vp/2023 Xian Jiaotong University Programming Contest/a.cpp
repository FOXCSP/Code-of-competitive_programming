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
	int x;
	cin >> x;
	if (x < 7) {
		cout << "water\n";
	} else {
		cout << "dry\n";
	}
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

