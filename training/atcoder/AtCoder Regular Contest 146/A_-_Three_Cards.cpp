#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

bool cmp(string a, string b) {
    if(a.size() != b.size()) return a.size() < b.size();
    for(int i = 0; i < a.size(); i ++) {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<string> s;
    while(n --) {
        string x; cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end(), cmp);
    string ans = "";
    int len = s.size();
    vector<string> b;
    for(int i = 1;i <= 3;i ++) {
        b.push_back(s[-- len]);
    }
    sort(b.begin(), b.end());
    for(int i = 2;i >= 0; i --) ans = ans + b[i];

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
