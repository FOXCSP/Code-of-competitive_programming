#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

map<string, int> mp;
void solve() {
    string s;
    cin >> s;
    mp["Monday"] = 1;
    mp["Tuesday"] = 2;
    mp["Wednesday"] = 3;
    mp["Thursday"] = 4;
    mp["Friday"] = 5;
    mp["Saturday"] = 6;
    mp["Sunday"] = 7;
    if(mp[s] == 7) cout << 6 << '\n';
    else cout << abs(mp[s] - 6) << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
