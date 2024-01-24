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
#define SZ(x) ((int)x.size())
#define vl vector<ll>;
#define vpp vector<pii>
#define lep(i, x, y) for (int i=(x);i<=(y);i++)
#define rep(i, y, x) for (int i=(y);i>=(x);i--)
#define all(x) x.begin(), x.end()
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

const int N = 1000010;

ll qmi(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
int d1, d2, d3, d4;
int x, y, a, b;
void work() {
	for (a = 0; a <= d1; a++)
    	for (b = 0; b <= d2; b++)
    		for (x = 0; x <= d3; x++)
    			for (y = 0; y <= d4; y++)
    				if (a+x==d1&&b+x==d2&&a+y==d3&&b+y==d4) {
    					// cout << a << ' ' << b << ' ' << x << ' ' << y << '\n';
    					return ;
    				}
}	
void solve() {
    freopen("dividing.in","r",stdin);
    freopen("dividing.out","w",stdout);
    cin >> d1 >> d2 >> d3 >> d4;
    work();
    ll cnt = 2, aa = qmi(2, a), bb = qmi(2, b), xx = qmi(2, x), yy = qmi(2, y);
    vector<array<ll, 3>> ans;
    int hf = (aa + bb);
    ans.pb({hf * (xx + yy) , hf * xx, hf * yy});
    x = max(x, y); cnt += x;
    while (x) {
    	ans.pb({hf * qmi(2, x), hf * qmi(2, x-1), hf * qmi(2, x-1)});
    	x--;
    }
    // while (y) {
    // 	ans.pb({hf * qmi(2, y), hf * qmi(2, y-1), hf * qmi(2, y-1)});
    // 	y--;
    // }
    ans.pb({aa + bb, aa, bb});
    a = max(a, b); cnt += a;
    while (a) {
    	ans.pb({qmi(2, a), qmi(2, a-1), qmi(2, a-1)});
    	a--;
    }
    // while (b) {
    // 	ans.pb({qmi(2, b), qmi(2, b-1), qmi(2, b-1)});
    // 	b--;
    // }
    cout << cnt << '\n';
    for (auto [a, b, c] : ans) {
    	cout << a << ' ' << b << ' ' << c << '\n';
    }
}

int main() {
	int _; cin >> _;
    while (_--) solve();
    return 0;
}