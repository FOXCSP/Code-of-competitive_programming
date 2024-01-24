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

const int N = 210;
int a[N], n;
void solve() {
	scanf("%d", &n);
	lep(i, 1, n) {
		a[i] = i;
	}
	if (n&1) {
		lep(now, 1, n) {
			int p = 0;
			lep(t, now+1, n) {
				if (p<(n-1)/2){
					printf("1 "); p++;
				} else {
					printf("-1 ");
				}
			}
		}
	} else {
		lep(now, 1, n) {
			lep(i, now+1, n) {
				if (i-now < n/2) printf("1 ");
				else if (i - now == n/2) printf("0 ");
				else printf("-1 ");
			}
		}
	}
	puts("");
}

int main() {
	int _;
	scanf("%d", &_);
	while (_--) solve();
	return 0;
}