#include <bits/stdc++.h>
#define int long long
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
typedef double db;
// head

void solve(int CaseT) {
	int x, y;
	cin >> x >> y;
	for (int a = 0; a <= x; a++) {
		if ((y - 1000*x + 1000*a) % 1500 == 0) {
			int c = (y - 1000*x + 1000*a) / 1500;
			int b = x - a - c;
			if (b >= 0 && c >= 0 && b * 1000 + 2500 * c == y) {
				cout << a << " " <<  (x - a - c) << " " << c << '\n';
				return ;
			}
		}
	} 
	cout << "-1\n";
}

signed main() {
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

