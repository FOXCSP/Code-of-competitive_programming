#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2, 0), b(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (*max_element(all(a)) != n) {
		cout << "NO\n";
		return ; 
	}
	a[n + 1] = n + 1;
	auto c = a;
	sort(all(a));
	for (int i = 1; i <= n; i++) {
		int p = lower_bound(all(a), i) - a.begin();
		b[i] = n - p + 1;
	}

	for (int i = 1; i <= n; i++) if (c[i] != b[i]) {
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _ = 1;
	cin >> _;
	for (; _--; ) {
		solve();
	}
		
	return 0;
}
