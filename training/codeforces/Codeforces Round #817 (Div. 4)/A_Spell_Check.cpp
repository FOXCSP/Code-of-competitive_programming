#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

string ans = "12345";
map<string, int> mp;
map<char, char> pp;
void solve() {
    pp['T'] = '1';
    pp['i'] = '2';
    pp['m'] = '3';
    pp['u'] = '4';
    pp['r'] = '5';
    string s;
    int n;
    cin >> n;
    cin >> s;
    if(n != 5) {
        cout << "NO\n";
    }
    else {
        string t;
        for(int i = 0;i < s.size(); i ++) t = t + pp[s[i]];
        if(mp.count(t) == 0) cout << "NO\n";
        else cout << "YES\n";
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    do {
        mp[ans] ++;
    }while(next_permutation(ans.begin(), ans.end()));
    // cout << mp.size() << endl;
    while(T --) solve();
    return 0;
}
