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

mt19937 rnd(time(0));
// head

const int N = 1000010, mod = 998244353;


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n = rnd() % 10 + 1;
	cout << n << " " << 1 << '\n';
	for (int i = 1; i <= n; i++) {
		cout << rnd() % 10 << " "; 
	} 
	cout << '\n';
	return 0;
}
