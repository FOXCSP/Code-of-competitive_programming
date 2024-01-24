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

const int N = 100010;
int n, m;

void solve() {
	cin >> n;
	vector<ll> cnta(27, 0), cntb(27, 0);
	auto modify = [&](vector<ll>& x, int k, string t) {
		for (auto c : t) {
			x[c-'a']+=k;
		}
	};

	auto check = [&](vector<ll> x, vector<ll> y) {
		int amin = 1e9, bmax = -1, acnt = 0, bcnt = 0;
		for (int i = 25; i >= 0; i--) {
			if (y[i] != 0) {
				if (bmax == -1) bmax = i;
				bcnt++;
			}
			if (x[i] != 0) {
				amin = min(amin, i);
				acnt++;
			}
		}
		if (amin != bmax) return amin < bmax;
		else {
			if (acnt > 1) return false;
			else {
				return x[amin] < y[bmax];
			}
		}
	};

	modify(cnta, 1, "a");
	modify(cntb, 1, "a");
	for (int i = 1; i <= n; i++) {
		int op, k;
		string s;
		cin >> op >> k >> s;
		if (op == 1) modify(cnta, k, s);
		if (op == 2) modify(cntb, k, s);
		if (check(cnta, cntb)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}

int main() {
	int _; cin >> _;
	while (_--)
	solve();
	return 0;
}