#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 2, 0);
	a[n + 1] = 1e9;
	a[0] = -1e9;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 0; i <= m; i++) {
		ans += lower_bound(a.begin(), a.end(), i) - a.begin() - 1;
	}
	cout << ans << '\n';
	return 0; 
} 
