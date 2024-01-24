#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define fi first
#define se second
#define P(T) pair<T, T>
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define all(T) T.begin(), T.end()
#define pb push_back 
using namespace std;
typedef long long ll;
typedef long double ldb;
//  head


void solve(int CaseT = 1) {
	int n;
	cin >> n;
	vec<int> a(n + 1, 0);
	int x = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i], x ^= a[i];
	// x = a ^ b
	
	int k = 0;
	for (int i = 30; i >= 0 && !k; i--)
		if (x >> i & 1)
			k = i;
	
	int y = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] >> k & 1)
			y ^= a[i];
	
	cout << (x ^ y) << " " << y << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_=1;
//	cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	
	return 0;
}

