#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 100010;
int a[N], f[N][2], n;

void solve() {
    cin >> n;

    for(int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[i - 1][0] + x;
    }
    cout << max(f[n][0], f[n][1]) << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
