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


int n;

void solve(int T) {
	cin >> n;
	vector<P(int)> a;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		y = -y;
		a.pb({x, y});
	}
	sort(a.begin(), a.end());
	
	vector<int> mx(n + 2, 0);
	
	for (int i = SZ(a) - 1; i >= 0; i--) {
		mx[i] = max(mx[i + 1], -a[i].se);
	}
	
	int ans = 1e9;
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		if (i + 1 < n) {
			ans = min(ans, abs(a[i].fi - mx[i + 1]));
		}
		if (i + 1 == n || mx[i + 1] < a[i].fi) {
			if (SZ(s)) {
				auto p = s.lower_bound(a[i].fi);
				if (p != s.end()) {
					ans = min(ans, *p - a[i].fi);
				}
				if (p != s.begin()) {
					ans = min(ans, a[i].fi - *prev(p));
				}
			}
		}
		s.insert(-a[i].se);
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

