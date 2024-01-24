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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	if (n < 1000) cout << n << '\n';
	else if (n < 10000) cout << n / 10 * 10 << '\n';
	else if (n < 100000) cout << n / 100 * 100 << '\n';
	else if (n < 1000000) cout << n / 1000 * 1000 << '\n';
	else if (n < 10000000) cout << n / 10000 * 10000 << '\n';
	else if (n < 100000000) cout << n / 100000 * 100000 << '\n';
	else if (n < 1000000000) cout << n / 1000000 * 1000000 << '\n';
	
	return 0;
} 
