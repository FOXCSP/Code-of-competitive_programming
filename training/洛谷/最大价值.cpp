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
    string s;
    cin >> s;
    int m = 0, ans = 0;
    for(int i = s.size() - 1;i>=0; i--) {
        if(s[i] == 'P') m ++;
        if(s[i] == 'A') ans = max(ans, m), m = 0;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    
    int T;cin >> T; 
    while(T --) solve();    
    return 0;
}
