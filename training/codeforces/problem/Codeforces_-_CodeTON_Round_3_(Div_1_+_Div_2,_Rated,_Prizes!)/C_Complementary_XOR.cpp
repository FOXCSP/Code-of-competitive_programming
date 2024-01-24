#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vi vector<int>
#define SZ(x) (x.size())
#define vl vector<ll>;
#define vpp vector<pii>
#define lep(i, x, y) for (int i=int(x);i<=int(y);i++)
#define rep(i, y, x) for (int i=int(y);i>=int(x);i--)
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
inline ll read() {
	ll s=0,f=1; char c = getchar();
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while ('0' <= c && c<='9') {s=s*10+c-'0';c=getchar();}
	return s*f;
}
void print(ll x) {if (!x) return ; if (x>9) print(x/10); putchar(x%10+'0');}
const int Mod = 1e9+7;
// --head--
int n;
string a, b;
vpp ans;
void solve() {
	cin >> n;
	cin >> a >> b;
	ans.clear();
	lep(i, 1, n-1) if ((a[i]==b[i]) != (a[i-1]==b[i-1])) {
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	if (a[0] != b[0]) {
		ans.pb({1, n});
		lep(i, 0, n-1) a[i] = ('1' - a[i]) + '0';
	}
	if (a[0] == '1') {
		ans.pb({1, n});
		ans.pb({2, n});
	}
	int last = 1, cnt=0;
	lep(i, 1, n-1) {
		if (a[i] == '1') cnt++;
		if (cnt&&(a[i] == '0' || i == n-1)) {
			if (a[i] == '1') {
				ans.pb({1, i+1});
				ans.pb({1, last});
			} else {
				ans.pb({1, i});
				ans.pb({1, last});
				last = i;
			}
			cnt=0;
		}
		if (a[i] == '0') last = i+1;
	}
	cout << SZ(ans) << '\n';
	lep(i, 0, SZ(ans)-1) {
		cout << ans[i].fi << " " << ans[i].se << '\n';
	}
}

int main() {
	int _; cin >> _;
	while(_--)
	solve();
	return 0;
}