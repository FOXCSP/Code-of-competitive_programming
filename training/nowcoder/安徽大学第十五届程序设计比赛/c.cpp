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
	int n, k;
	cin >> n >> k;
	vec<ll> a(n + 1, 0), s1(n + 2, 0), s2(n + 2, 0);
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
		s1[i] = s1[i - 1] + a[i];
	
	for (int i = n; i >= 1; i--)
		s2[i] = s2[i + 1] + a[i];
		
	for (int i = 1; i <= n / 2; i++)
		swap(s2[i], s2[n - i + 1]);
		
//	for (int i = 1; i <= n; i++) {
//		cout << s1[i] << " " << s2[i] <<'\n';
//	}
	
	ll l = 0, r = 1e18;	

	auto check = [&](ll x) {
		int p1 = upper_bound(s1.begin(), s1.end(), x) - s1.begin();
		int p2 = upper_bound(s2.begin(), s2.end(), x) - s2.begin();
		
//		cout << p1 << " " << p2 << '\n';
		if (p1 == SZ(s1)) return true;
		if (p2 == SZ(s2)) return true;
		
		
		if (n - p2 - p1 + 2 <= k) return true;
		return false;
	};
	
	while (l < r) {
		ll mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
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
