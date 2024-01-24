#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int t;
        string s;
        cin >> t >> s;
        for (int j = 0; j < t; j++) {
            if (s[j] == 'D') a[i] = (a[i] + 1) % 10;
            else a[i] = (a[i] - 1 + 10) % 10;
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
