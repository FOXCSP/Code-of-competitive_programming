#include <bits/stdc++.h>
#define fi first
#define se second
#define db double
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

void solve(int Tcase = 1) {
	string s;
	cin >> s;
	int n = SZ(s)-1;
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		l--,r--;
		k %= (r - l + 1);
		string t = s.substr(0, l) + s.substr(r-k+1, k) + s.substr(l, r-l+1-k) + s.substr(r+1, n-r);
		s = t;
	}
	cout << s << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _;
	_=1;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
