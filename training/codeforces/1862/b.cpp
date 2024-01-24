#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

void solve() {
	int n, m = 0;
	cin >> n;
	vector<int> a(n+1,0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> b(n * 2, 0);
	b[++m] = a[1];
	for (int i = 2; i <= n; i++) if (a[i] >= a[i - 1]) b[++m] = a[i]; else b[++m] = max(1, a[i] - 1), b[++m] = a[i];
	cout << m <<'\n';
	for (int i = 1; i <= m; i++) cout << b[i] << " \n"[i == m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _ = 1;
	cin >> _;
	for (; _--; ) {
		solve();
	}
		
	return 0;
}
