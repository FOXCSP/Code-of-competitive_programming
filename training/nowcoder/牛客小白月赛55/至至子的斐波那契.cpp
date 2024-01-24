#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

const ll N = 100;
ll fb[N];
ll fib(ll n) {
    if(n == 1ll || n == 2ll) {
        fb[n] = 1ll;
        return 1ll;
    }
    if(fb[n] != 0) return fb[n];
    else {
        fb[n] = fib(n - 1) + fib(n - 2);
        return fb[n];
    }

}

bool check(int m, ll x) {
    if(fb[m] < x) return true;
    return false;
}
void solve() {
    fib(N);
    int T;
    cin >> T;
    while(T --) {
        ll x;
        cin >> x;
        int  l = 0, r = 100;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(check(mid, x)) l = mid;
            else r = mid - 1;
        }
        ll a = fb[l], b = fb[l+1];
        if(abs(a - x) <= abs(b - x)) cout << l << endl;
        else cout << l + 1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
