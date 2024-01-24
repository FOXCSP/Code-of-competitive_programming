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
	int n;
	cin >> n;
	vec<ll> a(n + 1, 0), s(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	
	auto check = [&](int p) {
		return (a[p] <= s[p - 1]);
	};
	
	if (a[1] != 1) {
		cout << "NO\n";
		return ;
	} 
	
	for (int i = 2; i <= n; i++) {
		if (!check(i)) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int _; 
	cin >> _;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
