#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) (x.size())
#define vl vector<long long>;
#define vpp vector<pair<int,int>>
#define lep(i, x, y) for (int i=(x);i<=(y);i++)
#define rep(i, y, x) for (int i=(y);i>=(x);i--)
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--

const int N = 100010;
int a[N], n, m, b[N];
void solve() {
	scanf("%d", &n);
	lep(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1,a + n + 1);
	int ans = 0;
	int mid;
	if (n&1) mid= n-1>>1;
	else mid = n/2;
	int pos = 0;
	for (int i = 1, j = mid+1; i<=mid || j <= n; i++,j++) {
		if (j <= n) b[++pos] = a[j];
		if (i <= mid) b[++pos] = a[i];
	}
	for (int i = 2; i < n; i++) if (b[i] < b[i-1] && b[i] < b[i+1]) ans++;
	printf("%d\n", ans);
	lep(i, 1, n) printf("%d%c", b[i], " \n"[i == n]);
}

int main() {
	solve();
	return 0;
}