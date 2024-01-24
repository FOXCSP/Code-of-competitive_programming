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
// head
int g[10][10];
void solve(int CaseT) {
	int n, m;
	cin >> n >> m;
	vector<int> a(n*m);
	for (int i = 0; i < n * m; i++) {
		cin>>a[i];
	}
	sort(all(a));
	int t4 = a[n*m-1];
	int t3 = a[n*m-2];
	int t1 = a[0];
	int t2 = a[1];
	
	if (n > m) swap(n, m);
	
	ll ans = 1ll * ((n * (m - 1)) * (t4 - t1) + (n - 1) * (t3 - t1));
	
	ans = max(ans, 1ll * (n * (m - 1)) * (t4 - t1) + (n - 1) * (t4 - t2));
	
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
