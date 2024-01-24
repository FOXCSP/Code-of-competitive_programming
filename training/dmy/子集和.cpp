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
const int mod = 1000000007;
int f[1 << 17];
void solve(int CaseT = 1) {
	int n;
	cin >> n;
	// 1011
	for (int i = 0; i < 1 << n; i++) {
		f[i] = 1;
		// 1010
		// 1010 -> 1001 & 1011 -> 1001
		// 1001 -> 1000 & 1011 -> 1000
		// 1000 -> 0111 & 1011 -> 0011
		// 0011 -> 0010 & 1011 -> 0010
		// 0010 -> 0001 & 1011 -> 0001
		// 0001 -> 0000 & 1011 -> 0000
		
		// i = 10
		// 01 & 10
		for (int j = (i - 1) & i; j; j = (j - 1) & i) {
			f[i] = (f[i] + f[j]) % mod; 
		}
		if (i) f[i] = (1LL * f[i] * i) % mod;
		
	}
	
	for (int i = 0; i < 1 << n; i++)
		cout << f[i] << " ";
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

