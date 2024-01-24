#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define PII pair<int,int>
#define VI vector<int>
#define SZ(x) ((int)x.size())
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--

const int N = 200010;

int n, a[N];
void solve() {
	cin >> n;
	int cnt = 0;
	vector<int> v;
	v.pb(0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (SZ(v) == 0 || a[i] != v.back()) v.pb(a[i]);
	}
	n = SZ(v) - 1;
	if (n == 1) {
		cout << "YES\n";
		return ;
	}
	cnt += (v[1] < v[2]);
	cnt += (v[n - 1] > v[n]);
	if (cnt > 1) {
		cout << "NO\n";
		return ;
	}
	for (int i = 2; i <= n - 1; i++) {
		if ((v[i - 1] - v[i]) * (v[i] - v[i + 1]) < 0) cnt++;
	}
	if (cnt != 1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}


int main() {
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}