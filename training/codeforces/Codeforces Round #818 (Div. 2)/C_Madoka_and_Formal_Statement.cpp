#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 200010;
int a[N], n, b[N];

void solve() {
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    bool f = true;
    for(int i = 1;i <= n;i ++) {
        cin >> b[i];
        if(b[i] < a[i]) f = false;
    }

    if(f) {
        for(int i = n - 1; i >= 1; i --) {
            if(a[i] != b[i] && b[i] > b[i + 1] + 1) {
                f = false;
                break;
            }
        }
        if(a[n] != b[n] && b[n] > b[1] + 1) f = false;
    }
    if(f) cout << "YES\n";
    else cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
