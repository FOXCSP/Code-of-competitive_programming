#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 200010;
int n;
int a[N], s[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = 0;
        if (a[i] < i) s[i]++;
        s[i] += s[i - 1];
    }
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] < i) {
            ans += (s[a[i] - 1]);
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
