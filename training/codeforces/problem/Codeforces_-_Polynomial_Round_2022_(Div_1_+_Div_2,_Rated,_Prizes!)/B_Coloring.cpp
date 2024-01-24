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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m + 1, 0);
    ll mx = 0;
    ll sum = 0, same = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        if (mx < a[i]) {
            mx = a[i];
            same = 1;
        } else if (mx == a[i]) same++;
        sum += a[i];
    }
    sum -= mx;
    ll tot = (mx - 1) * (k - 1);
    // cout << sum << " " << tot << " " << same << '\n';

    puts(sum - same + 1 >= tot ? "YES" : "NO");
}

int main() {
    int _;cin >> _;
    while (_--)
    solve();
    return 0;
}