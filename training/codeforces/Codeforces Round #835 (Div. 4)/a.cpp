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

const int N = 100010;

void solve() {
	vector<int> a;
	for (int i = 1; i <= 3; i++) {
		int x;
		cin >> x;
		a.pb(x);
	}
	sort(a.begin(), a.end());
	cout << a[1] << '\n';
}

int main() {
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}