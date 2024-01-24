#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

void solve() {
    ll a, b, c = 0;
    cin >> a >> b;
    for(int i = 62;i >= 0; i --) {
        if(((a >> i)&1) == ((b >> i)&1)) c += (1ll<<i);
        else c += 0;
    }
    cout << c << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();    
    return 0;
}
