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

const int N = 210;
int n;
map<char, int> s, t;
void solve() {
	cin >> n;
	string str;
	cin >> str;
	str = "#" + str;
	for (int i = 1; i <= n; i++) {
		if (!s[str[i]]) s[str[i]] = i;
		t[str[i]] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (char x = 'a'; x <= 'z'; x++) {
			if (s[x] <= i && t[x] > i) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}

int main() {
	solve();
	return 0;
}