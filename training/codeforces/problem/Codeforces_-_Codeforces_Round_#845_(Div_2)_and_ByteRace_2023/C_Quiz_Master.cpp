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
int a[N];
map<int, int> mp;

void solve() {
	cin >> n >> m;
	mp.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	vector<vector<int>> div(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sqrt(a[i]); j++) {
			if (a[i] % j == 0) {
				div[i].pb(j);
				if (j != a[i] / j) div[i].pb(a[i] / j);
			}
		}
	}

	int l = 1, ans = 1e9, all = 0;
	for (int r = 1; r <= n; r++) {
		for (auto x : div[r]) {
			if (x <= m && mp[x] == 0) all++;
			mp[x]++;
		}
		if (all < m) continue;
		bool f1 = true;
		while (f1 && l < r) {
			for (auto x : div[l]) {
				mp[x]--;
				if (x <= m && mp[x] <= 0) {
					f1 = false;
				}
			}
			if (f1) {
				l++;
			} else {
				for (auto x : div[l]) {
					if (x <= m) mp[x]++;
				}
			}
		}
		ans = min(ans, a[r] - a[l]);
	}
	if (ans == 1e9) cout << "-1\n";
	else cout << ans << '\n';
}

int main() {
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}