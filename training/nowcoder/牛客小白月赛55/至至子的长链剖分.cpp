#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

const int N = 2e5+10;
queue<int> q[N];
void solve() {
    int n; cin >> n;
    int m = 0;
    for(int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        q[x].push(i);
        m = max(m, x);
    }
    if(q[m].size() > 1) {
        cout << "-1\n";
    }
    else {
        for(int i = m;i;i --) {
           if() 
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}
