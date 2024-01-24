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
const int N = 300010;
int a[N];
bool same(int x, int y) {
	if (a[x] == a[y]) return true;
	if (a[x] > a[y] && a[y] >= a[y - 1]) return true;
	if (a[x] < a[y] && a[y] <= a[y - 1]) return true;
	return false;
}
void solve(int CaseT) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	int  p = 2;
	while (p <= n && a[p] == a[p - 1]) {
		p++;
	}
	
	if (p > n) {
		cout << 1 << '\n';
		return ;
	}
	
	int ans = 2;
	int now;
	
	if (a[p] > a[p - 1]) now = 2;
	if (a[p] < a[p - 1]) now = 1;
	
	for (int i = p + 1; i <= n; i++) {
		if (a[i] == a[i - 1])
			continue;
		
		if (a[i] > a[i - 1] && now == 1) {
			ans++;
			now = 2;
		}
		
		if (a[i] < a[i - 1] && now == 2) {
			ans++;
			now = 1;
		}
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

/*

1
10
10 1 9 1 8 1 7 1 6 6
*/
