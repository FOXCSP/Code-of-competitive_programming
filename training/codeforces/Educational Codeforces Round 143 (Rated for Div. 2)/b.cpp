#include <bits/stdc++.h>
#define fi first
#define se second
#define pb emplace_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

// --head--

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(55, 0);
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		if (l <= k && k <= r) {
			a[l] += 1;
			a[r + 1] -= 1;
		}
	}
	for (int i = 1; i <= 50; i++) {
		a[i] += a[i - 1];
	}
	int cnt = 0;
	int mx = *max_element(a.begin(), a.end());
	for (int i = 1; i <= 50; i++) {
		if (a[i] == mx) {
			cnt++;
		}
	}
	if (a[k] == mx && cnt == 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}