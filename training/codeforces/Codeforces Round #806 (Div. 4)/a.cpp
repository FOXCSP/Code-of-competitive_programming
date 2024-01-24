#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}



void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < 3; i++) {
        if (s[i] < 'e') s[i] += 32;
    }
    if (s == "yes") cout << "YES\n";
    else cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
