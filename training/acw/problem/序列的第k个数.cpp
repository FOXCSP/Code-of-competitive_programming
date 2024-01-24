#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int mod = 200907;
int n;

int qmi(int a, int b) {
    int res = 1;
    for(; b; b >>= 1, a = (a * a) % mod)
        if(b & 1) res = (res * a) % mod;
    return res; 
}

void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int p;
    if(b - a == c - b) p = b - a;
    else p = b / a;

    if(p == b - a) {
        cout << a + (k - 1) * p % mod << '\n';
    }
    else {
        cout << a * qmi(p, k - 1) << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
