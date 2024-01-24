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

const int N = 1010;

int n, m1, m2;
vpp ans;
template<class T>
struct name {
	T p[N];
	void init() {for (int i = 1; i <= n; i++) p[i] = i; }
	int find(int x) {return x != p[x] ? p[x] = find(p[x]) : x; }
	void merge(int x, int y) {p[x] = y; }
};
name<int> p1, p2;
void solve() {
	cin >> n >> m1 >> m2;
	p1.init(), p2.init();
	lep(i, 1, m1) {
		int u, v;
		cin >> u >> v;
		int pu = p1.find(u), pv = p1.find(v);
		p1.merge(pu, pv);
	}
	lep(i, 1, m2) {
		int u, v;
		cin >> u >> v;
		int pu = p2.find(u), pv = p2.find(v);
		p2.merge(pu, pv);
	}
	lep(u, 1, n) lep(v, u + 1, n) {
		int pu1 = p1.find(u), pv1 = p1.find(v);
		if (pu1 == pv1) continue;
		int pu2 = p2.find(u), pv2 = p2.find(v);
		if (pu2 == pv2) continue;
		p1.merge(pu1, pv1);
		p2.merge(pu2, pv2);
		ans.pb({u, v});
	}
	cout << SZ(ans) << '\n';
	for (auto [u, v] : ans) {
		cout << u << " " << v << '\n';
	}

}
int main() {
	solve();
	return 0;
}