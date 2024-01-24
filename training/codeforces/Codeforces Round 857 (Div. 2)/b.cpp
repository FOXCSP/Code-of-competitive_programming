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

int n, m;

void solve(int T) {
	cin >> n;
	int a = 0, b = 0, c = 0, d = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x == 2) {
			a += b;
			b = d = 0;
			if (a) {
				if (a % 2 == 0) {
					c = a / 2 + 1;
				} else {
					c = (a - 1) / 2 + 1;
				}
			}
		} else {
			b++;
			d++;
		}
		ans = max(ans, c + d);
	}
	cout << ans << '\n';
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

