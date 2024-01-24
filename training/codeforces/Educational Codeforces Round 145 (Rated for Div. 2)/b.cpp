#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
using ll = long long;

const int inf = 1e9, mod = 998244353;

void solve(int caseT = 1) {
	ll n;
	cin >> n;
	if (n == 1) {
		cout << "0\n";
		return ;
	}
	ll x = sqrt(n) - 1;
	while (1ll * (x + 1) * (x + 1) < n) x++;
	cout << x << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	
	return 0;
}

