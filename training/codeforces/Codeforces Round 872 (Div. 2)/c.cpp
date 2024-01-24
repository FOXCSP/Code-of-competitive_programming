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

const int N = 100010;

int c[N], n, m;
void modify(int x, int y) {
	for (; x <= m; x += x & -x) 
		c[x] += y;
}

int query(int x) {
	int s = 0;
	for (; x; x -= x & -x)
		s += c[x];
	return s;
}

void solve(int CaseT) {
	cin >> n >> m;
	
	vector<int> a;
	int x1 = 0, x2 = 0;
	int x;
	for (int i = 1; i <= n; i++) {
		
		cin >> x;
		x1 += (x==-1);
		x2 += (x==-2);
		if (x > 0) {
			a.pb(x);
		}
	}
	
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	
	int ans = 0;
	
	ans = max(ans, SZ(a) + x1);
	ans = max(ans, SZ(a) + x2);
	ans = min(ans, m);
	
	for (int i = 0; i < SZ(a); i++) {
		int l = min(a[i] - 1, i + x1); 
		int r = min(m - a[i], SZ(a) - i - 1 + x2);
		ans = max(ans, l + r + 1);
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
