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
	int l, r;
	cin >> l >> r;
	if (l == r) {
		for (int i = 2; i <= l / i; i++) {
			if (l % i == 0) {
				cout << i << " " << l - i << "\n";
				return ;
			}
		}
	}	else {
		while (r & 1) --r;
		if (r / 2 != 1) { 
			cout << r / 2 << " " << r / 2 << '\n';
			return ;
		}
	}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// int _ = 1;
	// cin >> _;
	// for (; _--; ) {
	// 	solve();
	// }
	
	printf("%x", 2049417673);
	return 0;
} 
