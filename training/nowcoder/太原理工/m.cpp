#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define pb push_back
#define all(T) T.begin(), T.end()
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));

const int N = 10010;
int f[N], n, m;

void solve(int CaseT = 1) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int v, w;
		cin >> w >> v;
		for (int j = m; j >= v; j--) {
			f[j] = max(f[j], f[j - v] + w); 
		}
	}
	cout << f[m] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
