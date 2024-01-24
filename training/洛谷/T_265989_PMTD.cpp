#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e6+10;
int n, m;
int a[N];

void solve() {
    cin >> n >> m;
    pii mx = {2e9, 0};
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        if(mx.first > a[i]) mx.first = a[i];
        if(mx.second < a[i]) mx.second = a[i];
    }
    if(mx.second < 2) m --, mx.second += 2;
    ll res = mx.second;
    while(m) res = res * 2, m --;
    cout << res - mx.first << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();    
    return 0;
}
