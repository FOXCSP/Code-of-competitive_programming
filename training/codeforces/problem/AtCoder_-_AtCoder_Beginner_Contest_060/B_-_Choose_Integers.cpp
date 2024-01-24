#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define PII pair<int,int>
#define PLL pair<ll, ll>
#define VI vector<int>
#define SZ(x) ((int)x.size())
#define VL vector<ll>;
#define VPP vector<PII>
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int x = a % b;
	c = c % b;
	bool f = false;
	for (int t = 0; t <= b; t++) {
		if ((t * x) % b == c) {
			f = true;
			break;
		}
	}
	if (f) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	solve();
	return 0;
}