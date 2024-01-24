#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
typedef double db;
// head
void solve(int CaseT) {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n + 1, 0), s(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(all(a));
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	ll ans = 0;
	for (int i = 0; i <= k; i++) {
		int l = i * 2, r = n - (k - i);
		if (r < l) break;
		ans = max(ans, s[r] - s[l]);
	} 
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}
