#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e5+10;
ll a[N];

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    ll m = n;
    memset(a, 0, sizeof a);
    if(k*b > s || k*b < s - (n)*(k-1ll)) cout << "-1\n";
    else {
        while(m) {
            if(m == 0) break;
            if(m == n) {
                a[m] = k * b;
                s -= k * b;
            }
            else {
                if(s >= k - 1ll) 
                    a[m] = k - 1, s -= (k-1ll);
                else if(s) a[m] = s, s = 0ll;
            }
            m --;
        }
        if(s) a[n] += s;
        for(int i = 1;i <= n;i ++) {
            cout << a[i] << " "; 
        }
        cout << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
