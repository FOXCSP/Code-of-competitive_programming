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
#define VPP vector<pii>
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
inline ll read() {
	ll s=0,f=1; char c = getchar();
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while ('0'<= c&&c<='9') {s=s*10+c-'0';c=getchar();}
	return s*f;
}
void print(ll x) {if (!x) return ; if (x>9) print(x/10); putchar(x%10+'0');}
const int Mod = 1e9+7;
// --head--

int n, m, k;
void solve() {
	cin >> n >> m >> k;
	VI a(k + 1), v, s, t;
	int tot = 0;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		v.pb(a[i]);
	}
	sort(v.begin(), v.end());

	s.pb(0), t.pb(0);
	for (int i = k; i >= 1; i--) {
		if (v[i - 1] / 3 >= 2) s.pb(v[i - 1] / 3);
		if (v[i - 1] / 2 >= 2) t.pb(v[i - 1] / 2);
	}

	for (int i = 1; i < SZ(s); i++) {
		s[i] += s[i - 1];
	}
	for (int i = 1; i < SZ(s); i++) {
		cout << s[i] << " ";
	}
	
	cout << '\n';
	for (int i = 1; i < SZ(t); i++) {
		t[i] += t[i - 1];
	}
	for (int i = 1; i < SZ(t); i++) {
		cout << t[i] << " ";
	}

	cout << '\n';

	if (n % 2 != 0 && m % 2 != 0) {
		int id = lower_bound(s.begin(), s.end(), min(n, m)) - s.begin();
		if (s[id - 1] + 1 == min(n, m) || s.back() < min(n, m)) {
			cout << "xxxxxx\n" << s.back() << " " << min(n, m) << '\n';
			cout << "No\n";
			return ;
		}
		int res = 3 * (s[id] - s[id - 1]) + t[SZ(t) - 1] - t[id];
		tot += res;
		if (n < m) n -= 3;
		else m -= 3;
	} else tot = t.back();


	if (n >= 0 && m >= 0) {
		int need = (n + 1) / 2 * (m + 1) / 2;
		cout << need << " " << tot << "\n";
		if (need <= tot) cout << "Yes\n";
		else cout << "No\n";
	}
}

int main() {
	int _;
	cin >> _;
	while (_--)
	solve();
	return 0;
}