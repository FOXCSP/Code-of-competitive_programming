#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

int n;
string str[3];

void solve() {
    cin >> n;
    cin >> str[1] >> str[2];
    map<char, int> mp;
    mp['G'] = 1;
    mp['B'] = 1;
    mp['R'] = 0;
    bool f = true;
    for(int i = 0;i < n;i ++) {
        if(mp[str[1][i]] != mp[str[2][i]]) {
            f = false;
            break;
        }
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
