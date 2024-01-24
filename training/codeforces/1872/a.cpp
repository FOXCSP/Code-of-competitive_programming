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
	double a, b;
	int c;
	cin >> a >> b >> c;
	if (a > b) swap(a, b);
	b -= a;
	cout << ((int)(ceil(b / 2)) + c - 1) / c << '\n';	
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
