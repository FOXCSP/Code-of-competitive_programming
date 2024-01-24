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

const int N = 200010;
const ll mod = 998244353; 
int n, m;
int s[600010];
int fr, rr;
ll qmi(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}
void solve(int CaseT = 1) {
	cin >> m;
	n = 1;
	ll ans = 1;
	s[++rr] = 1;
	for (; m--;) {
		int op, x;
		cin >> op;
		if (op == 1) {
			cin >> x;
			ans = (ans * 10 + x) % mod;
			n++;
			s[++rr] = x;
		} 
		if (op == 2) {
			ans = (ans - s[++fr] * qmi(10, n - 1) % mod + mod) % mod;
			n--;
		}
		if (op == 3) {
			cout << ans << '\n'; 
		}
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
