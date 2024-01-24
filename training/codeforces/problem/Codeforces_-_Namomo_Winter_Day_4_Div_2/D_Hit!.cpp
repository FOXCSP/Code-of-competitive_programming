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
using db=double;
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
typedef pair<db, db> Point;

const db eps = 1e-5;
const db EPS = 1e-15;
Point a, b;
struct Circle {
	Point mi;
	db r;
};

db dis(Point a, Point b) {
	return sqrt(1.0*(a.fi-b.fi)*(a.fi-b.fi)+1.0*(a.se-b.se)*(a.se-b.se));
}

bool in(Circle x, Point a) {
	return dis(a, x.mi) < x.r;
}

Point Hf(Point a, Point b) {
	return Point{(a.fi+b.fi)/2.0, (a.se+b.se)/2.0};
}

void solve() {
	Circle a, b;
	db x, y, r;
	cin >> x >> y >> r;
	a.mi = {x, y};
	a.r = r;
	cin >> x >> y >> r;
	b.mi = {x, y};
	b.r = r;
	Point L = a.mi, R = b.mi;
	while(dis(L, R) >= EPS) {
		Point mid = Hf(L, R);
		if (in(a, mid) && in(b, mid)) {
			printf("%.12f %.12f\n", mid.fi, mid.se);
			return ;
		}
		if (in(a, mid)) L = mid;
		else R = mid;
	}
	if (in(a, L) && in(b, L)) printf("%.12f %.12f\n", L.fi, L.se);
}

int main() {
	solve();
	return 0;
}