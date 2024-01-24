#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 110;
int n;
int a[N];
bool st[N];
void solve() {
    cin >> n;
    vector<int> ans;
    if((n - 2) & 1) {
        ans.push_back(1);
        ans.push_back(n - 2);
        ans.push_back(n);
        for(int i = n;i; i --) {
            if(i == n || i == n - 2 || i == 1) continue;
            cout << i << " ";
        }
    }
    else {
        ans.push_back(n - 1);
        ans.push_back(n);
        for(int i = n - 2;i >= 1;i --) cout << i << " ";
    }
    for(auto c : ans) {
        cout << c << " \n"[c == ans.back()];
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
