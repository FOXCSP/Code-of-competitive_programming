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
    int n; cin >> n;
    string s; cin >> s;
    pair<char,int> mn = {s[0], 1};
    vector<pair<char,int>> res; 
    for (int i = 0; i < SZ(s); i++) {
        char c = s[i];
        if (mn.fi > c) {
            mn = {c, i+1};
        } else if (mn.fi == c) {
            if (s[i - 1] < s[mn.se]) res.pb({s[i - 1], i + 1});
        }
    }
    int k = 0;
    if (mn.fi < s[0]) k = mn.se;
    else if (SZ(res)) {
        sort(res.begin(), res.end());
        k = res[0].se;
    }
    for (int i = 0; i < k; i++) {
        reverse(s.begin() + i, s.begin() + i + k);
    }
    cout << s << '\n';
    cout << k << '\n';
}

int main() {
	int _; cin >> _;
    while(_--)
    solve();
}
