#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}


void solve() {
    int n, m;
    cin >> n >> m;
    n --, m --;
    if(n == 0 && m == 0) cout << "Tonya\n";
    else if((n == 0 && m & 1) || (m == 0 && n & 1)) cout << "Burenka\n";
    else {
        if((n+m)%2 ==0) {
            cout << "Tonya\n";
        }
        else {
            cout << "Burenka\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while( T -- ) {
        solve();
    }
    return 0;
}
