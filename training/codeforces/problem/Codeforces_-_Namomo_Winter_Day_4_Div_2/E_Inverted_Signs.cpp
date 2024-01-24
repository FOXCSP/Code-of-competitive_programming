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

const int N = 1000010;
int a[N], n;
ll ans;
void solve() {
    cin >> n;
    PII mx = {1e9, 0}, mx2 = {0, 0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1) {
            int x = abs(a[i] - a[i - 1]);
            int y = abs(-a[i] - a[i - 1]);
            // printf("%d : [%d - %d = %d]\n", i, y, x, y - x);
            ans += x;
            if (y - x < mx.fi) {
                mx2 = mx;
                mx = {y - x, i};
            } else if (y - x < mx2.fi) {
            	mx2 = {y - x, i};
            }
        }
    }
    if (n == 1) ans = 0, mx = {0, 0};
    // cout << ans << '\n';
    cout << ans + min(0, mx.fi) + min(0, mx2.fi) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}