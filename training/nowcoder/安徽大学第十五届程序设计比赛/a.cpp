#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define fi first
#define se second
#define P(T) pair<T, T>
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define all(T) T.begin(), T.end()
#define pb push_back 
using namespace std;
typedef long long ll;
typedef long double ldb;
//  head


void solve(int CaseT = 1) {
	int n;
	cin >> n;
	vec<P(int)> vx;
	for (int i  =1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vx.pb({a * 9 + b * 3 + c, i});
	} 
	sort(all(vx));
	reverse(all(vx));
	for (auto [x, y] : vx) {
		cout << y << " ";
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_=1;
	cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	
	return 0;
}
