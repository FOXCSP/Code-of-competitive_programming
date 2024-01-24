#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}



void solve() {
    int n;
    string s;
    map<char, int> mp;
    cin >> n >> s;
    for (auto c : s) {
        mp[c]++;
    }
    int ans = 0;
    for (auto c : mp) {
        ans += c.second;
    }
    cout << ans + (mp.size()) << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
