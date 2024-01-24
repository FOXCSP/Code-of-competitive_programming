#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define all(T) T.begin(), T.end()
#define pb push_back 
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const ll mod = 998244345;

void solve(int CaseT = 1) {
	srand((unsigned(time(0))));
	int n = random(100000) + 1;
	cout << n << '\n';
	map<P(ll), ll> mp;
	for (int i = 1; i <= n; i++) {
		ll a = random(mod);
		ll b = random(mod);
		ll c = random(mod);
		if (mp.count(MP(a, b)) != 0) 
			i--;
		else 
			cout << a << " " << b << " " << c << '\n'; 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
//	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
} 
