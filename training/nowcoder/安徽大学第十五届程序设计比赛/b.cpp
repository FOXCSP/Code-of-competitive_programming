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
	vec<int> l(n + 1, 0), r(n + 1, 0), a(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		l[i] = i - 1;
		r[i] = i + 1;
	}
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	int k;
	cin >> k;
	
	ll now = a[k];
	
	ll cnt = 0;
	
	while (1) {
		bool f = 0;
		if (l[k] > 0 && a[l[k]] < now) {
			l[r[k]] = l[k];
			r[l[k]] = r[k];
			now += a[l[k]];
			k = l[k];
			cnt++;
			f = 1;
		}
		
		if (r[k] < n + 1 && a[r[k]] < now) {
			r[l[k]] = r[k];
			l[r[k]] = l[k];
			now += a[r[k]];
			cnt++;
			k = r[k];
			f = 1;
		}
		
		if (!f) {
			break;
		}
	}
	if (cnt < n - 1) {
		cout << "An inevitable process\n";
	} else {
		cout << "A perfect meal\n";
	}
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
