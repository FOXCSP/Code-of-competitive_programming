#include <bits/stdc++.h>
//#define int long long
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
mt19937_64 rnd(time(0));
// head

pair<int, int> e[500005];
map< pair<int, int>, bool > h;

ll random(ll x) {
	return 1ll * rand() * rand() % x;
}

int main() {
	srand(unsigned(time(0)));
	cout << 1 <<'\n';

	int n = rand() % 10000 + 2;
	int m = rand() % 20000 + 1;
	int q = rand() % 20000 + 1;
	
	cout << n << " " << m << " " << q << '\n';
	
	for (int i = 1; i < n; i++) {
		int fa = random(i) + 1;
		e[i] = {fa, i + 1};
		h[e[i]] = h[{i + 1, fa}] = 1; 
	}
	for (int i = n; i <= m; i++) {
		int x, y;
		do {
			x = random(n) + 1;
			y = random(n) + 1;
		} while (x == y);
		e[i] = {x, y};
		h[e[i]] = h[{y, x}] = 1;
	}
	random_shuffle(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++)
		cout << e[i].fi << " " << e[i].se << " " << (rand() % 10000000000 + 1) <<'\n';
	for (; q--; ) {
		int w = rand() % 10000000000 + 1;
		cout << w << '\n';
	}
	return 0;
}

