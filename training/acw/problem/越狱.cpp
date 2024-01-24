// m^n - m*(m-1)^(n-1)
#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int mod = 100003;
int qmi(int a,int b) {
    a %= mod;
    int res = 1;
    for(; b; b >>= 1, a = (a * a) % mod)
        if(b&1) res = (res * a) % mod;
    return res % mod;
}

int phi() {
    int res = mod;
    int t = mod;
    for(int i = 2;i <= t / i; i ++) {
        if(t % i == 0) {
            res = res * (i - 1) / i;
            while(t % i == 0) t /= i;
        }
    }
    if(t > 1) res = (res * (t - 1) / t);
    return res;
}

int n, m;
void solve() {
    cin >> m >> n;
    int tmod = phi(), p = n - 1;
    if(__gcd(m, p) == 1) p %= tmod;
    else if(p >= tmod) p = p % tmod + tmod; 
    cout << (m % mod * (qmi(m, p) - qmi(m - 1, p)) % mod) % mod << "\n";
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
