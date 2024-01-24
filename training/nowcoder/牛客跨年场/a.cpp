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
int a, b, n, k;
int w[N][N], logn;
int mx[N][N][12], mn[N][N][12];

int query(int x, int y) {
    int t1 = mx[x+n-(1<<logn)][y][k];
    int t2 = mx[x][y+n-(1<<logn)][k];
    int t3 = mx[x+n-(1<<k)][y+n-(1<<k)][k];
    int t4 = mx[x][y][k];
    int mxx = max(t1, max(t2, max(t3, t4)));
    t1 = mn[x+n-(1<<logn)][y][k];
    t2 = mn[x][y+n-(1<<logn)][k];
    t3 = mn[x+n-(1<<k)][y+n-(1<<k)][k];
    t4 = mn[x][y][k];
    int mnn = min(t1, min(t2, min(t3, t4)));
    return mxx - mnn;
}


void solve() {
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++) {
            scanf("%d", &w[i][j]);
            mx[i][j][0] = mn[i][j][0] = w[i][j];
        }
    for (logn=0; (1<<(logn+1))<=n;logn++);
    for (int k = 1; k < logn; k++) {
        for (int i = 0; i + (1<<k) < a; i++) {
            for (int j = 0; j + (1<<k) < b; j++) {
//mx[i][j][k] -> mx[i][j][k - 1], mx[i+(1<<(k-1))][j][k-1], mx[i+(1<<(k-1))][j+(1<<(k-1))][k-1], mx[i][j+(1<<(k-1))][k-1];
                mx[i][j][k] = max(mx[i][j][k-1], max(mx[i+(1<<(k-1))][j+(1<<(k-1))][k-1], 
                                max(mx[i+(1<<(k-1))][j][k-1], mx[i][j+(1<<(k-1))][k-1])));
                mn[i][j][k] = min(mn[i][j][k-1], min(mn[i+(1<<(k-1))][j+(1<<(k-1))][k-1], 
                                min(mn[i+(1<<(k-1))][j][k-1], mn[i][j+(1<<(k-1))][k-1])));
            }
        }
    }
    int ans = 1 << 30;
    for (int i = 1; i + n <= a; i++)
        for (int j = 1; j + n <= b; j++)
            ans = min(ans, query(i, j));
    printf("%d\n", ans);
}

int main() {
	solve();
	return 0;
}