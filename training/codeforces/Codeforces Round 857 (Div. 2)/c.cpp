#include <bits/stdc++.h>
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;

void solve(int T) {
	int n, m;
	cin >> n >> m;
	cout << n * m << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << (i << 10) + j << " \n"[j == m];
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cin.tie(nullptr);
	int _;
	cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}

