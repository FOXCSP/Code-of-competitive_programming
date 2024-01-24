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


int n, m;
void solve() {
	cin >> n;
	VI a(n + 1), pos(n + 1, 0), x(n + 1), y(n + 1), v;
	vector<vector<int>> num(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
		num[a[i]].pb(i);
	}
	VI p0, p2;
	for (int i = 1; i <= n; i++) {
		if (SZ(num[i]) > 2) {
			cout << "NO\n";
			return ;
		}
		if (SZ(num[i]) == 1) {
			x[pos[i]] = i; y[pos[i]] = i;
		} else if (SZ(num[i]) == 2) {
			p2.pb(i);
		} else {
			p0.pb(i);
		}
	}


// cout << SZ(p0) << " " << SZ(p2) << '\n';
	if (SZ(p0) != SZ(p2)) {
		cout << "NO\n";
		return ;
	} else {
		if (SZ(p0) && SZ(p2)) {
			sort(p0.begin(), p0.end());
			p0.erase(unique(p0.begin(), p0.end()), p0.end());
			sort(p2.begin(), p2.end());
			p2.erase(unique(p2.begin(), p2.end()), p2.end());

			int l = SZ(p0) - 1;
			int r = l;
			while (l >= 0 && r >= 0) {
				int i1 = num[p2[r]][0];
				int i2 = num[p2[r]][1];
				if (p2[r] < p0[l]) {
					cout << "NO\n";
					return ;
				}
				x[i1] = p2[r];
				x[i2] = p0[l];
				y[i2] = p2[r];
				y[i1] = p0[l];
				l--, r--;
			}
		}
		cout << "YES\n";
		for (int i = 1; i <= n; i++) 
			cout << x[i] << " \n"[i == n];
		for (int i = 1; i <= n; i++) 
			cout << y[i] << " \n"[i == n];
		
	}
}

int main() {
	int _;
	cin >> _;
	while (_--)
	solve();
	return 0;
}