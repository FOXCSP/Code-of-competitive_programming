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

const int N = 200010;
int n, m, idx;
int a[N], ans[N];
map<int, int> mp;
void solve() {
	cin >> n;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	mp.clear();
	mp[n]++;
	ans[1] = mx;
	sort(a + 1, a + n + 1);
	int t = 30, now = mx;
	for (int i = 2; i <= n; i++) {
		int res = 0, resi = 0;
		if (t) {
			for (int j = 1; j < n; j++) {
				if (!mp[j]) {
					if (res < (now | a[j])) {
						res = (now | a[j]);
						resi = j;
					}
				}
			}
			mp[resi]++;
			now |= a[resi];
			ans[i] = a[resi];
			t--;
		}
	}
	vector<int> x;
	for (int i = 1; i <= n; i++) {
		if (mp[i] == 0) x.pb(a[i]); 
	}
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i]) cout << ans[i] << " \n"[i == n];
		else cout << x[idx++] << " \n"[i == n];
	}
}

int main() {
	int _; cin >> _;
	while (_--)
	solve();
	// cout << ll(999815193ll|15277088ll) << '\n';
	// cout << ll(999815193ll|913891315ll) << '\n';
	return 0;
}