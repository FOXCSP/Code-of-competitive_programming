#include <bits/stdc++.h>
#define fi first
#define se second
#define db double
#define ldb long double
#define lp (p<<1)
#define rp (p<<1|1)
#define vec vector
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define setdb cout<<fixed<<setprecision(12);
using namespace std;
typedef long long ll;
ll qmi(ll a, ll b, ll mod)
{ll res=1; while(b) { if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;} return res;}
/* -- head -- */

ldb pi = acos(-1);

void solve(int Tcase = 1) {
	int n;
	cin >> n;
	vec<pair<ldb, int>> a;
	for (int i = 1; i <= n; i++) {
		ldb x, y;
		cin >> x >> y;
		ldb z = pow((x * x + y * y), 0.5);
		a.pb({atan2(y, x), i});
	}
	sort(a.begin(), a.end());
	int x, y;
	ldb mn = 1e9;
	
	if (a.back().fi * a[0].fi < 0) {
		ldb t1 = a[0].fi + pi;
		ldb t2 = pi - a.back().fi;
		x = a.back().se;
		y = a[0].se;
		mn = t1 + t2;
	}
	
	
	for (int i = 1; i < SZ(a); i++) {
		if (abs(a[i].fi - a[i - 1].fi) < mn) {
			mn = a[i].fi - a[i - 1].fi;
			x = a[i - 1].se;
			y = a[i].se;
		}
	}
	cout << x << " " << y << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _; 
//	cin >> _;
	_=1;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
