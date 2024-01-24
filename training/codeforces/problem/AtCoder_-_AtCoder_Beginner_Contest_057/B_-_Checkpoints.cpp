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


int operator + (PII a, PII b) {
	return (abs(a.fi - b.fi) + abs(a.se - b.se));
}
int n, m;
vector<PII> stu, ple;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		stu.pb({x, y});
	}
	for (int i = 1; i <= m; i++) {
		int x, y; cin >>x >> y;
		ple.pb({x, y});
	}
	for (int i = 0; i < n; i++) {
		int ans = 1e9, ot = 1;
		for (int j = 0; j < m; j++) {
			int res = stu[i] + ple[j];
			if (ans > res) {
				ans = res;
				ot = j + 1;
			}
		}
		cout << ot << "\n";
	}
}

int main() {
	solve();
	return 0;
}