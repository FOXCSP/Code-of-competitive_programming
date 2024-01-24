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
int n, cnt[10];
void solve() {
	cin >> n;
	for (int i= 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x < 400) cnt[0]++;
		else if (x < 800) cnt[1]++;
		else if (x < 1200) cnt[2]++;
		else if (x < 1600) cnt[3]++;
		else if (x < 2000) cnt[4]++;
		else if (x < 2400) cnt[5]++;
		else if (x < 2800) cnt[6]++;
		else if (x < 3200) cnt[7]++;
		else cnt[8]++;
	}
	int ans = 0;
	for (int i = 0; i <= 8; i++) {
		if (i < 8 && cnt[i]) ans++;
		if (i == 8) ans += cnt[i];
	}
	cout << max(1, ans - cnt[8]) << " " << ans << '\n';
}

int main() {
	solve();
	return 0;
}