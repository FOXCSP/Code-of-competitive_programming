#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

// --head--

int n;
void solve() {
	cin >> n;

	vector<ll> a(n + 1, 0), b(n + 1, 0), cnt(n + 2, 0);
	vector<ll> preb(n + 1, 0);
	vector<ll> ans(n + 1, 0);
	vector<P(ll)> add;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) preb[i] = b[i] + preb[i - 1];

	for (int i = 1; i <= n; i++) {
		ll x = a[i];
		
		int l = i - 1, r = n;
		auto check = [&](int p) {
			return a[i] >= (preb[p] - preb[i - 1]);
		};
		

		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (check(mid)) l = mid;
			else r = mid - 1; 
		}

		cnt[i] += 1;
		cnt[l + 1] -= 1;
		if (l + 1 <= n && x < preb[l + 1]) {
			add.pb({l + 1, x - preb[l] + preb[i - 1]});
		}
	}

	for (int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		ans[i] += cnt[i] * b[i];
	}
	for (auto [i, w] : add) {
		ans[i] += w;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " \n"[i == n];
	}
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}
