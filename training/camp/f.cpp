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

ll n, k;
void solve() {
    cin >> n >> k;
    ll ans = 1ll << 50;
    for (int i = 1; i <= k; i++) {
        ll cnt = i;
        ll t = k - cnt, res = 1;
        cnt = cnt + min(cnt, (n - cnt) / 2);
        while (cnt + t < n) {
            if (n - cnt >= 2) {
                res++;
                cnt = cnt + min(cnt, (n - cnt)/2);
            } else {
                res = 1ll << 50;
                break;
            }
        }
        if (cnt < n) res++;
        ans = min(ans, res);
    }
    if (ans == 1ll << 50) ans = 1;
    cout << ans <<'\n';
}

int main() {
    solve();
    return 0;
}