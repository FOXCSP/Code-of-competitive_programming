#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

string s[10];

void solve() {
    map<char, int> mp;
    for(int i = 1;i <= 2;i ++)
        for(int j = 1;j <= 2;j ++)
            {
                char c;
                cin >> c;
                // cout << c << " ";
                mp[c ] ++;
            }
    int l = mp.size();
    if(l == 1) {
        cout << 0 << '\n';
    }
    if(l == 2) {
        cout << 1 << "\n";
    }
    if(l == 3) {
        cout << 2 << '\n';
    }
    if(l == 4) {
        cout << 3 << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
