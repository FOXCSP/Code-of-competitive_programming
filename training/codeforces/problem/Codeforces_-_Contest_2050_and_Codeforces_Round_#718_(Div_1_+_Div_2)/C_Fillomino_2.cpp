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
const int N = 510;
int g[N][N];
int n, a[N];
void solve() {
	scanf("%d", &n);
	lep(i, 1, n) scanf("%d", &a[i]);
	lep(i, 1, n) {
		pii nxt = {i, i};
		lep(x, 1, a[i]) {
			if (!g[nxt.fi][nxt.se]) 
				g[nxt.fi][nxt.se] = a[i];
			if (nxt.se == 1 || g[nxt.fi][nxt.se-1]) nxt = {nxt.fi+1, nxt.se};
			else nxt = {nxt.fi, nxt.se-1};
		}
	}
	lep(i, 1, n) {
		lep(j, 1, i) {
			printf("%d%c", g[i][j], " \n"[j == i]);
		}
	}
}

int main() {
	solve();
	return 0;
}