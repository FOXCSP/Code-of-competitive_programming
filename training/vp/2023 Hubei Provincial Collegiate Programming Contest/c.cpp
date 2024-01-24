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
typedef double db;
// head

int main() {
	int n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n == 1) cout << m / 2 + 1 << '\n';
	else cout << max(n, m) << '\n';
	return 0;
} 
