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
	int mn = min(n, m);
	int d = max(n, m) - min(n, m);
	cout << mn + (d + 1) / 2 << '\n';
	return 0;
} 
