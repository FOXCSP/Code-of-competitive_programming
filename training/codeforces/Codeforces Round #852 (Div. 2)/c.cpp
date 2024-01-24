#include <bits/stdc++.h>
#define fi first
#define se second
#define pb emplace
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

// --head--

void solve() {
	int n;
	cin >> n;
	vector<P(int)> a(n + 1, {0, 0});
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a.begin(), a.end());
	int l = 1, r = n;
	int L = 1, R = n;
	while (l < r && L < R) {
		int p1 = a[l].se, p2 = a[r].se;
		if (p1 < p2) {
			if (p1 > L && p2 < R) {
				cout << p1 - 1 << " " << p2 + 1 << '\n';
				return ;
			}
			if (p1 <= L) L++, l++;
			if (p2 >= R) R--, r--;
		} else {
			if (p1 < R && p2 > L) {
				cout << p2 - 1 << " " << p2 + 1 << '\n';
				return ;
			}
			if (p2 <= L) L++, r--;
			if (p1 >= R) R--, l++;
		}
	}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _;
	cin >> _;
	while (_--) solve();
	return 0;
}